# Contributing to VYRO Studio

Thank you for your interest in contributing to VYRO Studio. This project is in the **research and architectural design phase** — no executable code exists yet.

## How to Contribute

### Research & Design
- Review and comment on open RFCs in `docs/architecture/`
- Propose improvements to the plugin ABI or encoder/output interfaces
- Share static analysis findings from other streaming applications (using read-only tools only)

### Documentation
- Improve clarity of research summaries in `docs/research/`
- Add missing architectural diagrams (Mermaid / ASCII)
- Translate documentation (PRs welcome)

### Code (Future)
When implementation begins:
- Follow the coding standards in `.editorconfig`
- Write tests for new modules
- Update relevant documentation with each change
- Ensure CI passes before requesting review

## Development Workflow

1. Fork the repository
2. Create a feature branch: `git checkout -b feat/your-feature`
3. Make changes with clear, atomic commits
4. Run local checks: `./scripts/check.sh` (when available)
5. Open a Pull Request against `main`

## Pull Request Guidelines

- **Title**: Conventional Commits format (`feat:`, `fix:`, `docs:`, `refactor:`, etc.)
- **Description**: Explain the motivation, approach, and any trade-offs
- **Scope**: One logical change per PR; split large changes
- **Tests**: Include tests for new behavior
- **Docs**: Update `docs/` if architecture or interfaces change

## Code Style

- C/C++: C++20, clang-format (config in `.clang-format` when added)
- CMake: 3.20+, modern syntax
- Markdown: wrap at 100 chars, use relative links

## Reporting Issues

Use the issue templates:
- **Bug Report** — for defects in documentation or tooling
- **Feature Request** — for architectural proposals
- **Security** — see [SECURITY.md](SECURITY.md)

## License

By contributing, you agree that your contributions will be licensed under the project's license (Apache-2.0 for code, CC-BY-4.0 for docs) unless otherwise stated.

## Questions?

Open a Discussion or check existing issues before starting work.