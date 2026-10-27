# VYRO Studio Roadmap

> **Living document** — subject to change as research concludes.

## Phase 0 — Foundations (Weeks 1–3)

### Completed
- [x] Initialize repository with CI, issue templates
- [x] Basic CMake/MSVC build configuration (CMake 4.0, MSVC x64)
- [x] Working Windows CI (GitHub Actions on windows-2022)

### Incomplete (Phase 0)
- [ ] Linting and formatting configuration
- [ ] Finalize plugin ABI specification (C header + JSON schema)
- [ ] Define encoder/output/service interfaces
- [ ] Choose UI framework (e.g., Dear ImGui or WinUI 3)
- [ ] Evaluate graphics/rendering backend separately; do not select one yet
- [ ] Establish dependency-manager selection (vcpkg/Conan)

## Phase 1 — Core Skeleton (Weeks 4–8)
- [ ] `vyro-core.dll` / `vyro.so` — plugin loader, refcount, settings (`vyro_data_*`)
- [ ] Scene graph API (`vyro_scene_*`, `vyro_sceneitem_*`)
- [ ] Source/filter base classes + plugin entry point
- [ ] Minimal headless test harness (no GUI)

## Phase 2 — Media Pipeline (Weeks 9–14)
- [ ] Video I/O abstraction (`vyro_video_output_*`, `vyro_video_frame_*`)
- [ ] Audio I/O abstraction (`vyro_audio_output_*`, `vyro_audio_resampler_*`)
- [ ] Encoder plugin interface (`vyro_encoder_*`) — FFmpeg + vendor HW
- [ ] Output plugin interface (`vyro_output_*`) — streaming (RTMP/SRT) + recording (MP4/MKV)

## Phase 3 — GUI & UX (Weeks 15–22)
- [ ] Main window, scene editor, source properties panel
- [ ] Live preview canvas (GPU-accelerated)
- [ ] Settings persistence (JSON + migration)
- [ ] Theme system (dark/light + user themes)

## Phase 4 — Hardening & Polish (Weeks 23–30)
- [ ] CFG/GS/XFG equivalent hardening on all platforms
- [ ] Fuzzing harness for parser/plugin boundary
- [ ] Sandbox/privilege separation for plugin processes
- [ ] Telemetry/observability (opt-in)
- [ ] Installer, auto-update, code signing

## Ongoing
- [ ] Documentation parity with code
- [ ] Community plugins / example plugins
- [ ] Cross-platform: macOS (CoreVideo/AudioToolbox), Linux (VAAPI/VA-API, PipeWire)