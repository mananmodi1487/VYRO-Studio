# OBS Studio Static Analysis — Research Summary

> **Source:** Read-only static analysis of OBS Studio 32.2.2 binaries (`obs64.exe`, `obs.dll`) using **REA (Reverse Engineering Anything)** by **morluto** (https://github.com/morluto/rea) — MIT License.
>
> **Method:** PE header inspection, import/export table enumeration, resource directory scan, certificate parsing, entropy analysis. **No decompiler backend was configured** (Ghidra/Hopper/IDA/Kuna unavailable). No target was executed, modified, or uploaded.

---

## Targets Analyzed

| Binary | Size | Architecture |
|--------|------|--------------|
| `obs64.exe` | 5.33 MB | PE32+, x86_64 |
| `obs.dll` | 1.12 MB | PE32+, x86_64 |

Both binaries are part of **OBS Studio 32.2.2**, obtained from the official installer. No local binary fingerprints (SHA-256 hashes, absolute paths) are published here — the analysis is reproducible against any OBS Studio 32.2.2 installation.

---

## Digital Identity (Both Binaries)

- **Publisher:** OBS Project, LLC (Wyoming, US)
- **Certificate chain:** OBS Project, LLC → DigiCert G5 CS ECC SHA384 2021 CA1 → DigiCert CS ECC P384 Root G5
- **Algorithm:** ECDSA with SHA-384 (OID `1.2.840.10045.2.1`)
- **Verification:** REA decodes structure only — **no cryptographic verification of chain, timestamp, or Authenticode digest coverage**.

---

## `obs64.exe` — GUI Frontend

### Import Graph (31 DLLs, 3,494 functions)

| DLL | Functions | Role |
|-----|-----------|------|
| `Qt6Widgets.dll` | 1,563 | GUI framework |
| `obs.dll` | 769 | **libobs core** (see below) |
| `Qt6Core.dll` | 572 | Qt core |
| `Qt6Gui.dll` | 309 | Qt rendering |
| `MSVCP140.dll` | 89 | MSVC C++ stdlib |
| `KERNEL32.dll` | 70 | Win32 base |
| `obs-frontend-api.dll` | 17 | Frontend bridge |
| `libcurl.dll` | 9 | HTTP/RTMP push |
| `avcodec-62.dll` / `avformat-62.dll` | 4 / 4 | FFmpeg encode/mux |
| `dxgi.dll` | 1 (`CreateDXGIFactory1`) | GPU capture |
| `w32-pthreads.dll` | 5 | Threading |

**Key architectural insight:** `obs64.exe` is a thin Qt6 frontend that delegates all streaming/recording logic to `obs.dll` (769 imported functions) and `obs-frontend-api.dll` (17 functions).

### Security Hardening
- **GS (stack cookie):** Present
- **CFG:** `IMAGE_GUARD_CF_INSTRUMENTED` set; check/dispatch/XFG pointers populated; **function table empty** — REA notes this is a *linker claim* not verified by inspection.
- **TLS:** 8-byte region, **0 callbacks**.
- **Resources:** 21 directories (RT_VERSION × 13, RT_ICON, RT_MANIFEST).

---

## `obs.dll` — libobs Core Engine

### Export Table (1,784 Named Exports)

The complete public libobs plugin ABI:

| Domain | Count | Examples |
|--------|-------|----------|
| **scene / sceneitem** | 92 | `obs_scene_create`, `obs_scene_add`, `obs_sceneitem_set_pos`, `obs_sceneitem_get_draw_transform` |
| **source** | 158 | `obs_source_create`, `obs_source_create_private`, `obs_source_add_filter`, `obs_source_draw` |
| **filter** | 2 | `obs_filter_get_parent`, `obs_filter_get_target` |
| **audio** | 31 | `obs_audio_output_open`, `audio_resampler_*`, `obs_add_raw_audio_callback`, `obs_get_audio_monitoring_device` |
| **video** | 55 | `obs_video_encoder_create`, `obs_add_raw_video_callback`, `video_output_*`, `video_frame_*`, `video_format_*` |
| **encoder** | 70 | `obs_encoder_create`, `obs_encoder_*` (ROI, scaling, group, packet), `obs_enum_encoder_types` |
| **output** | 64 | `obs_output_start`/`obs_output_stop`, `obs_output_*` (callbacks, congestion, delay, protocols) |
| **service** | (in plugin/load) | `obs_service_create`, `obs_service_apply_encoder_settings`, `obs_service_get_supported_*_codecs` |
| **plugin / module load** | 22 | `obs_load_all_modules`, `obs_load_all_modules2`, `obs_post_load_modules`, `obs_load_source`, `gs_load_*` |
| **data / settings** | 156 | `obs_data_*` (create/from JSON/file, arrays, autoselect, typed getters/setters) |
| **property / UI** | 81 | `obs_property_*` (editable list, frame-rate options, typed fields) |
| **object / refcount** | 3 | `obs_object_get_ref`, `obs_object_get_weak_object`, `obs_object_release` |

### Import Graph (29 DLLs, 278 Functions)

| DLL | Functions | Role |
|-----|-----------|------|
| `KERNEL32.dll` | 74 | Win32 base (loading, memory, threads, files, mitigation) |
| `avutil-60.dll` | 15 | FFmpeg core utils |
| `w32-pthreads.dll` | 15 | Threading |
| `avformat-62.dll` | 14 | FFmpeg mux/demux |
| `avcodec-62.dll` | 9 | FFmpeg encode/decode |
| `swscale-9.dll` | 7 | FFmpeg scaling |
| `swresample-6.dll` | 6 | FFmpeg audio resampling |
| `zlib.dll` | 3 | Compression |
| `dxgi.dll` | 1 (`CreateDXGIFactory1`) | GPU capture |
| `AVRT.dll` | 2 | Multimedia thread scheduling |

**No managed imports** — pure native C++.

### Security Hardening
- **GS:** Present in `.data`
- **CFG:** `IMAGE_GUARD_CF_INSTRUMENTED`; check/dispatch/XFG pointers; **function count = 0** (linker claim).
- **TLS:** 56-byte region, **0 callbacks**.
- **Resources:** Only 2 resources — RT_MANIFEST (id 24) + one other (id 16). **No icon, no version info** in DLL.

### Entropy
- File entropy: **6.5473** (normal for code+data).
- **3 high-entropy blocks (>7.2)** at file end — likely compressed/embedded assets.

---

## Architecture Inferred from Static Evidence

```
obs64.exe (Qt6 GUI)
       │
       ├── obs.dll (libobs core) — 769 imports, 1,784 exports
       │       ├── Scene graph (obs_scene_*, obs_sceneitem_*)
       │       ├── Source/filter pipeline (obs_source_*, obs_filter_*)
       │       ├── Audio I/O (obs_audio_output_*, audio_resampler_*)
       │       ├── Video I/O (video_output_*, video_frame_*)
       │       ├── Encoder abstraction (obs_encoder_*, obs_enum_encoder_types)
       │       ├── Output streaming/recording (obs_output_*)
       │       ├── Settings persistence (obs_data_*)
       │       └── Plugin lifecycle (obs_load_all_modules, gs_load_*)
       │
       ├── obs-frontend-api.dll (17 exports) — UI bridge
       └── Qt6Widgets/Qt6Core/Qt6Gui — UI framework
```

---

## Limitations of This Analysis

1. **No decompilation** — function bodies, control flow, algorithms, and string literals were not recovered.
2. **No string extraction** — `list_strings` requires decompiler backend.
3. **No segment/procedure inventory** — `binary_overview`, `list_documents`, `list_segments` unavailable.
4. **Signature not verified** — Authenticode chain/timestamp/digest coverage not cryptographically validated.
5. **Version strings opaque** — RT_VERSION payloads not decoded by REA's resource parser.
6. **Binary layout unavailable** — `inspect_binary_layout` is Linux-only (`pwntools-elf`).

---

## What CAN Be Established Without a Decompiler

✅ Complete public export table (1,784 functions with addresses)  
✅ Import dependency graph (29 DLLs, 278 functions for `obs.dll`)  
✅ Digital identity (OBS Project, LLC, DigiCert-signed, ECDSA SHA-384)  
✅ Security hardening profile (GS/CFG/XFG/TLS)  
✅ Entropy map (normal + 3 high-entropy tail blocks)  
✅ Resource inventory (manifest only)  
✅ The libobs plugin ABI surface from export names

---

## Implications for VYRO Studio

The export table of `obs.dll` effectively documents the **libobs plugin ABI contract**. VYRO Studio can design its own `vyro-abi` mirroring these domains (scene, source, encoder, output, etc.) while choosing different implementation strategies (UI framework, plugin format, settings model). The import graph confirms the core is native C++ with FFmpeg, libcurl, and pthreads — all available for clean-room reimplementation.

**No OBS code was copied.** All observations are structural and derived from public interfaces.

---

*Analysis performed 2026-10-27 using `rea-agents@6.8.0` via MCP stdio channel.*