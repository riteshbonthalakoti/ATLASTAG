# AtlasTag Fabrication Outputs (Gerbers & Drill)

> **STATUS: PRELIMINARY CHECKPOINT EXPORT — STRICTLY NOT FOR FABRICATION**  
> **Date:** October 9, 2026  
> **Tool:** KiCad 10.0.6 (`kicad-cli`)

---

## Critical Notice

These Gerber and Excellon drill files represent the Week 1 prototype board outline (45 × 35 mm on `Edge.Cuts`) and preliminary footprint placements for toolchain validation.

### Engineering Fabrication Gate:
- **Routing Status:** Incomplete. Full signal routing (SPI, UART, SIM) and internal ground/power plane polygon pours (`In1.GND`, `In2.PWR`) are not completed.
- **DRC Verification:** **NOT VERIFIED.** KiCad Design Rules Check (DRC) requires interactive GUI verification and has not been executed.
- **Ordering Advisory:** **DO NOT ORDER, SUBMIT, OR QUOTE THESE GERBERS FOR PCB FABRICATION.** Production manufacturing outputs will only be generated after schematic signoff, complete manual PCB routing, ground pour stitching, and a clean KiCad GUI DRC report.
