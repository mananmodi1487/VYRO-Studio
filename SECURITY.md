# Security Policy

## Supported Versions

VYRO Studio is currently in the **research and architectural design phase**. No executable releases exist yet. This policy will be updated when the first release is published.

| Version | Supported |
|---------|-----------|
| Pre-release | ❌ No security support |

## Reporting a Vulnerability

If you discover a security issue in this repository (e.g., in documentation, tooling, or future code), please report it responsibly:

1. **Do not** open a public issue.
2. Email **security@vyro.studio** (placeholder — update when project email is established) with:
   - Description of the vulnerability
   - Steps to reproduce (if applicable)
   - Potential impact
   - Suggested fix (if any)
3. Allow reasonable time for assessment before public disclosure.

## Security Considerations for Contributors

- **No secrets in code**: API keys, tokens, passwords, or credentials must never be committed. Use `.gitignore` and secret scanning.
- **Static analysis only**: All reverse-engineering work in this project uses **read-only static analysis** (REA). No target binaries are executed, no process injection occurs, and no dynamic analysis is performed.
- **No OBS code**: This project does not copy, bundle, or redistribute OBS Studio code, assets, or binaries. Architectural observations are derived from public interfaces only.
- **Dependencies**: Future implementation will pin and verify all third-party dependencies (FFmpeg, libcurl, etc.) via checksums and reproducible builds.

## Attribution

Static analysis in this project was performed using **REA (Reverse Engineering Anything)** by **morluto** — https://github.com/morluto/rea — MIT License.

VYRO Studio is **not affiliated with OBS Studio** or the OBS Project.