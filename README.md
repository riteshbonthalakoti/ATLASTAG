# AtlasTag

![AtlasTag Banner](docs/images/atlastag_banner.jpg)

> A compact, low-power, globally connected asset-tracking platform.


## Project

AtlasTag is a Hack Club Half Life hardware project exploring how a slim, portable device can combine GNSS positioning, cellular IoT connectivity, motion sensing, local telemetry storage, and aggressive power management.

## Current Status

Week 1 — PCB Design (Modular Prototype Baseboard).

![AtlasTag Baseboard 3D Render](docs/images/atlastag_pcb_render.png)
*AtlasTag Week 1 Modular Prototype Baseboard (45 × 35 mm, 4-Layer Controlled Impedance Stackup).*

Current work:
- Modular iron-solderable baseboard schematic & 4-layer PCB layout
- Verified Li-Po charging (MCP73831) and ultra-low-dropout 3.3V regulation (AP2112K)
- Telemetry queue storage (Winbond W25Q32 SOIC-8) and motion sensor header
- Cellular/GNSS platform evaluation (Decoupled via 16-pin mezzanine interface)


## Planned System

High-level planned capabilities:

- GNSS positioning
- LTE-M / NB-IoT connectivity
- motion detection
- battery-powered operation
- local telemetry storage
- remote telemetry
- companion mobile application

These are planned capabilities and are subject to engineering validation during development.

## Repository Structure

- `docs/`: Documentation, requirements, architecture, and research.
- `hardware/`: KiCad project files, footprints, symbols, and gerbers.
- `firmware/`: MCU firmware source code.
- `software/`: Companion application or server-side scripts.
- `bom/`: Bill of materials and component sourcing.
- `simulations/`: Hardware and antenna simulation files.
- `tests/`: Automated and manual testing scripts.

## Development Workflow

All active development occurs on `dev`.

Changes intended for the stable project state are submitted through pull requests:

dev → main

Pull requests are manually reviewed and merged.

## Hack Club Half Life

This project is being developed as part of Hack Club Half Life.

## License

*(Pending deliberate decision)*
