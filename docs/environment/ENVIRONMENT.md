# AtlasTag Development Environment

## Operating System
- **OS**: Microsoft Windows 11 Pro 10.0.26200

## Core Tools
- **Git**: git version 2.55.0.windows.3
- **GitHub CLI**: gh version 2.97.0
  - Authenticated as `riteshbonthalakoti` (Active)
- **Python**: Python 3.12.10
- **Node.js**: v24.19.0

## CAD / Hardware Tooling
- **KiCad Version**: 10.0.6 (Installed via winget for current user)
- **KiCad CLI Executable**: `C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\kicad-cli.exe`
- **KiCad GUI Executable**: `C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\kicad.exe`
- **KiCad Python Executable**: `C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\python.exe` (includes `pcbnew` 10.0.6)
- **Standard Symbol Libraries**: `C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\share\kicad\symbols` (Verified present)
- **Standard Footprint Libraries**: `C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\share\kicad\footprints` (Verified present)
- **PATH Configuration Note**: The KiCad binary directory is not on the Windows system or user `PATH`. The project and its automation workflows explicitly use the verified absolute executable paths instead.

## Notes
- Environment is ready for initial documentation, architecture, research, schematic capture, and DRC/ERC validation.
- Git is configured and repository is initialized on active branch `dev`.
