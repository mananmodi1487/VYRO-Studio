# VYRO Studio

> **Research / Early Development** — An independent streaming and recording application built from scratch, with its own UI, branding, and implementation.

[![Status](https://img.shields.io/badge/status-research%20%2F%20early%20development-orange.svg)](#status)
[![License](https://img.shields.io/badge/license-Apache%202.0-blue.svg)](LICENSE)

---

## Overview

VYRO Studio is a **new, independent** streaming and recording application for Windows (with future cross-platform goals). It is **not a fork, rebrand, or derivative** of OBS Studio. The project is in the **research and architectural design phase** — no executable code exists yet.

The goal is to build a clean-room implementation that learns from OBS Studio's architectural patterns (plugin model, encoder abstraction, scene graph, output pipeline) while making different technical choices:
- Modern UI framework (e.g., ImGui, WebGPU, or native WinUI)
- Explicitly typed plugin API with versioning
- Built-in telemetry/observability hooks
- Security-first defaults (hardening, sandboxing where feasible)

## Status

| Area | State |
|---|---|
| Core architecture | 📐 Design / RFC |
| Plugin ABI | 📝 Specification draft |
| Encoder abstraction | 📝 Specification draft |
| UI framework selection | 🔍 Evaluating |
| Build system / CI | 📋 Planned |
| Executable prototype | ❌ Not started |

**No downloads, installers, or runnable builds are available.**

## Research Foundation

Architectural observations were derived from **read-only static analysis** of OBS Studio 32.2.2 binaries (`obs64.exe`, `obs.dll`) using **[REA (Reverse Engineering Anything)](https://github.com/morluto/rea)** — an MIT-licensed static analysis toolkit by **morluto** (https://rea.tools/).

Key verified observations (no decompilation, no execution):
- `obs.dll` exports **1,784 public symbols** forming the libobs plugin ABI (scenes, sources, filters, audio, video, encoders, outputs, settings, plugin loading).
- Import graph shows Qt6 GUI layer over a native C++ core; FFmpeg (`avcodec`, `avformat`, `swscale`, `swresample`), `libcurl`, `w32-pthreads`, and DXGI for capture.
- Security hardening: GS stack cookies, CFG (`IMAGE_GUARD_CF_INSTRUMENTED`), XFG; TLS present but no callbacks.
- Digital signature: OBS Project, LLC (DigiCert ECDSA SHA-384 chain).

**Limitations:** Analysis was purely structural (PE headers, import/export tables, resource directory). No function bodies, control flow, or string content were recovered — no decompiler backend was configured. See `docs/research/LIMITATIONS.md`.

Full research summary: [`docs/research/OBS_STATIC_ANALYSIS.md`](docs/research/OBS_STATIC_ANALYSIS.md)  
Export surface catalog: [`docs/research/LIBOBS_API_SURFACE.md`](docs/research/LIBOBS_API_SURFACE.md)

## Attribution

- **REA (Reverse Engineering Anything)** by **morluto** — https://github.com/morluto/rea — MIT License
- Static analysis performed via REA's MCP server (`rea-agents@6.8.0`)

## Independence & Licensing

VYRO Studio is **not affiliated with OBS Studio** or the OBS Project.
OBS Studio source code (LGPLv2.1+/GPLv2) at https://github.com/obsproject/obs-studio remains the reference for any licensed reuse. No OBS code, assets, branding, or artwork are included in this repository.

VYRO Studio source code is licensed under the **Apache License 2.0** (see `LICENSE`).
Documentation and research artifacts are CC-BY-4.0 unless otherwise noted.

## Roadmap

See [ROADMAP.md](ROADMAP.md) for phased milestones.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) and [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## Security

See [SECURITY.md](SECURITY.md) for vulnerability reporting.

---

*Last updated: 2026-10-27*