# Architecture Overview

> **Status:** Draft — subject to change as research concludes.

## High-Level Module Map

```
┌─────────────────────────────────────────────────────────────────┐
│                        VYRO Studio                              │
├─────────────────────────────────────────────────────────────────┤
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐          │
│  │   vyro-gui   │  │  vyro-core   │  │ vyro-plugins │          │
│  │  (UI layer)  │  │  (engine)    │  │  (dynamic)   │          │
│  └──────┬───────┘  └──────┬───────┘  └──────┬───────┘          │
│         │                 │                 │                   │
│         └─────────────────┼─────────────────┘                   │
│                           ▼                                     │
│              ┌────────────────────────┐                          │
│              │    vyro-abi (C API)    │                          │
│              │  scene, source, filter,│                          │
│              │  encoder, output, ...  │                          │
│              └───────────┬────────────┘                          │
│                           │                                      │
│         ┌─────────────────┼─────────────────┐                   │
│         ▼                 ▼                 ▼                   │
│  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐             │
│  │  FFmpeg     │  │  libcurl    │  │  Platform   │             │
│  │  (avcodec,  │  │  (HTTP/     │  │  Capture    │             │
│  │   avformat, │  │   transport)│  │  (DXGI/     │             │
│  │   swscale)  │  │             │  │   VAAPI)    │             │
│  └─────────────┘  └─────────────┘  └─────────────┘             │
└─────────────────────────────────────────────────────────────────┘
```

**Note:** The diagram above shows libcurl as an HTTP transport layer. It is **not** the implementation of RTMP, SRT, or HLS streaming protocols. Those protocols require separate protocol-specific implementations. Output protocol implementations and their dependencies remain to be evaluated before media work begins.

## Core Modules

### `vyro-core` (Engine)
- Plugin loader & lifecycle (`vyro_module_load`, `vyro_post_load`)
- Reference-counted object model (`vyro_ref`, `vyro_weak_ref`)
- Settings / data model (`vyro_data_*` — JSON-compatible, typed)
- Scene graph (`vyro_scene_*`, `vyro_sceneitem_*`) — tree, groups, transforms, blending
- Source/filter pipeline (`vyro_source_*`, `vyro_filter_*`) — async, audio, video, draw callbacks

### `vyro-abi` (Public C API)
Stable, versioned C header (`vyro.h`) defining:
- Opaque handles: `vyro_scene_t`, `vyro_source_t`, `vyro_encoder_t`, `vyro_output_t`, `vyro_service_t`
- Function pointers for plugin entry points
- Error codes (`vyro_result_t`)
- Version macros: `VYRO_API_VERSION`, `VYRO_ABI_VERSION`

### `vyro-plugins` (Dynamic)
Discovered at runtime from `plugins/` directory:
- **Source plugins**: camera, screen capture, media file, browser, text, color
- **Filter plugins**: color correction, crop, scale, chroma key, audio gain/noise gate
- **Encoder plugins**: x264, NVENC, AMF, QSV, audio (AAC, Opus)
- **Output plugins**: RTMP, SRT, HLS, file recording (MP4, MKV, FLV)
- **Service plugins**: Twitch, YouTube, custom RTMP endpoints

### `vyro-gui` (UI Layer)
- Independent of core — communicates via `vyro-abi`
- Technology TBD: ImGui (Dear ImGui + docking), WinUI 3, or WebGPU + WASM
- Scene editor, source properties, audio mixer, preview canvas
- Theme system (dark/light + user themes)

## Data Flow

```
User Action (GUI)
      │
      ▼
vyro-abi call (e.g., vyro_source_create)
      │
      ▼
vyro-core: validate → load plugin → instantiate source
      │
      ▼
Plugin entry point → returns vyro_source_t
      │
      ▼
Pipeline: source → filters → encoder → output
      │                    │            │
      ▼                    ▼            ▼
  Frame callbacks    Encoded packets   Network / File
```

## Plugin ABI Contract

Each plugin exports:
```c
typedef struct {
    const char* name;
    const char* version;
    int abi_version;          // must match VYRO_ABI_VERSION
    vyro_result_t (*load)(vyro_plugin_context_t*);
    vyro_result_t (*unload)(void);
    // type-specific callbacks...
} vyro_plugin_info_t;
```

Plugins are loaded once at startup; unload on shutdown.

## Security Hardening Targets

| Feature | Target |
|---------|--------|
| Stack protection | `/GS` (Windows), `-fstack-protector-strong` (Linux/macOS) |
| Control Flow Guard | `/guard:cf` (Windows), `-fcf-protection` (Linux) |
| XFG | `/guard:xfg` (Windows) |
| ASLR | Default on all platforms |
| DEP/NX | Default on all platforms |
| Sandbox | Plugin processes isolated (future) |

## Cross-Platform Considerations

| Subsystem | Windows | macOS | Linux |
|-----------|---------|-------|-------|
| Video capture | DXGI / Media Foundation | CoreVideo / AVFoundation | VAAPI / PipeWire / V4L2 |
| Audio capture | WASAPI | AudioToolbox | PipeWire / PulseAudio / ALSA |
| Hardware encode | NVENC / AMF / QSV | VideoToolbox | NVENC / VAAPI / AMF |
| Network | WinINet / libcurl | Network.framework / libcurl | libcurl |
| UI | WinUI 3 / ImGui | AppKit / ImGui | GTK4 / Qt6 / ImGui |

---

*See `ROADMAP.md` for phased implementation plan.*