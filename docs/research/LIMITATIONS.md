# Limitations of Static Analysis

This document explains what the Phase 3–4 REA-based static analysis **cannot** tell us, and why.

---

## 1. No Decompiler Backend Configured

**Tools affected:**
- `binary_overview` — requires Ghidra/Hopper/IDA/Kuna
- `list_documents` — requires decompiler
- `list_segments` — requires decompiler
- `list_strings` — requires decompiler
- `list_procedures` — requires decompiler
- `inspect_binary_layout` — requires `pwntools-elf` (Linux x64 only)

**Result:** All returned `provider_unavailable` or `capability_unavailable`.

**What this means:**
- No function boundaries, control flow graphs, or basic blocks
- No pseudocode (C-like decompilation)
- No decoded string literals
- No segment/section inventory with permissions
- No cross-references (callers/callees)
- No type recovery (structures, classes, vtables)

---

## 2. Authenticode Signature Not Cryptographically Verified

**Tool:** `inspect_pe_certificates`

**REA's explicit limitations:**
> *"This workflow does not verify signatures, certificate chains, timestamps, or Authenticode digest coverage of image bytes. PKCS#7 fields are decoded structurally; cryptographic validity remains unobserved."*

**What we have:** Structural decode of the PKCS#7 `signedData` — certificate fields, OIDs, issuer/subject strings, digest algorithms.
**What we lack:** Chain validation to trusted root, timestamp verification, hash coverage of the PE image (excluding the certificate table itself).

---

## 3. Version Resource Strings Not Decoded

**Tool:** `inspect_pe_resources`

**REA's explicit limitations:**
> *"Static PE32/PE32+ type/name/language resource inventory; payloads other than RT_GROUP_ICON remain opaque."*

**What we have:** Resource directory inventory — 21 directories for `obs64.exe`, 2 for `obs.dll`. RT_VERSION entries present (13 in `obs64.exe`).
**What we lack:** `FileVersion`, `ProductVersion`, `ProductName`, `LegalCopyright`, `CompanyName`, `FileDescription`, `InternalName`, `OriginalFilename` strings.

---

## 4. Binary Layout Unavailable on Windows

**Tool:** `inspect_binary_layout`

**REA's explicit limitation:**
> *"The initial real-verified pwntools artifact profile supports Linux x64 only."*

**What we lack:** Section table with raw/virtual sizes, permissions (R/W/X), alignment, entry point mapping, overlay detection.

---

## 5. No Dynamic / Runtime Behavior

**By design (safety constraints):**
- No target execution
- No process attachment or injection
- No memory dumping
- No API hooking or instrumentation
- No network traffic capture
- No UI interaction

**What we cannot observe:**
- Actual plugin loading order at runtime
- Heap/stack behavior
- Thread synchronization patterns
- Encoder initialization sequences
- Network protocol negotiation (RTMP handshake, etc.)
- GPU resource allocation (DXGI swap chains, textures)
- Crash/Exception behavior

---

## 6. Export Table ≠ Runtime API Surface

**Tool:** `inspect_native_exports`

**REA's explicit limitation:**
> *"Rows reproduce the PE export directory; they do not establish that an export is reachable, safe to call or loaded at runtime. Forwarded exports resolve in another DLL, which is not opened; ordinal-only exports have no name in this image."*

**What we have:** 1,784 named exports with RVAs.
**What we lack:**
- Which exports are actually called by `obs64.exe` (import cross-reference needed)
- Calling conventions, parameter types, return types
- Thread-safety guarantees
- Lifetime/ownership semantics
- Deprecated vs. stable APIs

---

## 7. Import Table ≠ Actual Dependencies

**Tool:** `inspect_pe_imports`

**What we have:** 31 DLLs / 3,494 imports for `obs64.exe`; 29 DLLs / 278 imports for `obs.dll`.
**What we lack:**
- Delay-load imports (none found in `obs64.exe`, but possible in other binaries)
- Dynamic `LoadLibrary`/`GetProcAddress` calls not in IAT
- Plugin DLLs loaded via `obs_load_all_modules` (not in IAT)
- Version-specific imports (e.g., `Qt6Widgets.dll` vs `Qt5Widgets.dll`)

---

## 8. Entropy ≠ Encryption

**Tool:** `inspect_byte_entropy`

**REA's explicit limitation:**
> *"Entropy does not prove encryption; compressed and encrypted bytes cannot be distinguished by this measure."*

**What we have:** File entropy 6.55, 3 blocks >7.2 at file end.
**What we lack:** Distinction between compressed data (zlib, LZ4), encrypted data (AES), packed code (UPX, custom), or high-entropy resources (shaders, embedded fonts).

---

## 9. No Type / Structure Recovery

Without a decompiler:
- No `struct` / `class` definitions
- No vtable layouts
- No enum values
- No constant propagation
- No macro expansion

---

## 10. Platform-Specific Gaps

| Gap | Impact |
|-----|--------|
| No macOS analysis (`native-macos` provider `unsupported_host`) | Cannot inspect Mach-O, codesign, entitlements, dyld |
| No Linux ELF analysis (`pwntools-elf` Linux-only) | Cannot inspect Linux OBS build |
| No Java/Android analysis (`rea-artifact-graph` `inspect_asset_catalog` macOS-only) | Cannot inspect Android OBS (if any) |
| No .NET analysis (`rea-dotnet-static` available but OBS is native) | N/A for OBS |

---

## Summary: What We Can vs. Cannot Claim

| Claim | Supported? |
|-------|------------|
| "OBS uses Qt6" | ✅ Yes (import table) |
| "OBS uses FFmpeg avcodec/avformat/swscale/swresample" | ✅ Yes (import table) |
| "libobs exports 1,784 functions" | ✅ Yes (export table) |
| "libobs has scene/source/encoder/output APIs" | ✅ Yes (export name patterns) |
| "OBS is signed by OBS Project, LLC" | ✅ Yes (certificate decode) |
| "OBS has CFG/GS/XFG hardening" | ✅ Yes (load config) |
| "OBS's encoder rate control algorithm is X" | ❌ No (needs decompilation) |
| "OBS's scene item transform math is Y" | ❌ No (needs decompilation) |
| "OBS's audio resampler uses algorithm Z" | ❌ No (needs decompilation) |
| "OBS's plugin ABI is stable across versions" | ❌ No (needs version comparison) |
| "VYRO Studio can copy libobs function signatures" | ⚠️ Risky — names only, no types/semantics |

---

## Path Forward for VYRO Studio

1. **Design from first principles** using the export *names* as a domain vocabulary, not a signature contract.
2. **Consult OBS source code** (LGPLv2.1+/GPLv2 at https://github.com/obsproject/obs-studio) for implementation details — this is the authoritative reference.
3. **Consider enabling Ghidra later** (free, Apache-2.0, JDK 21+) for targeted decompilation of specific modules (`obs.dll` encoder logic, `obs-outputs.dll` streaming pipeline).
4. **Validate at runtime** with a test harness once VYRO Studio has a prototype — static analysis is a starting map, not the territory.

---

*This document reflects the state of knowledge as of 2026-10-27. Update when decompiler backend is added or new binaries are analyzed.*