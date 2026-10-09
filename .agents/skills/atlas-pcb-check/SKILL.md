---
name: atlas-pcb-check
description: >-
  Inspect and validate KiCad schematics and PCB layout files for AtlasTag using the KiCad 10 CLI.
  Executes Electrical Rules Checks (ERC), Design Rules Checks (DRC), and verifies RF clearance rules.
  Use when validating schematics, checking board layouts, or preparing manufacturing outputs.
---

# AtlasTag KiCad PCB & Schematic Validation Procedure

Use this skill to perform automated rule checks, inspect layout constraints, and review KiCad files for the AtlasTag project.

---

## Operating Guidelines

- **Verified CLI Path:** Always invoke the KiCad CLI using its absolute path:
  ```powershell
  & "C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\kicad-cli.exe" <subcommand>
  ```
  Do not assume or modify the Windows `PATH` environment variable.
- **File Existence Gate:** Verify that target schematic (`.kicad_sch`) or PCB (`.kicad_pcb`) files actually exist before running CLI commands. If no design files exist, report that fact immediately.
- **Honest Violation Reporting:** Never claim zero errors or warnings without inspecting the actual CLI report output.
- **Engineering Reality:** Passing automated ERC/DRC does not prove RF performance, antenna efficiency, battery life, or regulatory compliance.

---

## Step-by-Step Procedure

### 1. Pre-Check File Existence
- Verify project directory `hardware/kicad/`.
- Confirm presence of:
  - Project file: `hardware/kicad/atlastag.kicad_pro`
  - Schematic file: `hardware/kicad/atlastag.kicad_sch`
  - Layout file: `hardware/kicad/atlastag.kicad_pcb`
- If files do not exist, halt with: *"No KiCad schematic/PCB files exist yet to validate."*

### 2. Run Schematic Electrical Rules Check (ERC)
When `atlastag.kicad_sch` exists:
```powershell
& "C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\kicad-cli.exe" sch erc `
  --severity-all `
  --output "hardware/kicad/erc_report.txt" `
  "hardware/kicad/atlastag.kicad_sch"
```
- Read `erc_report.txt` and report:
  - Total Errors and Total Warnings.
  - Unconnected pins, input/output contention, or floating power rails.

### 3. Run PCB Design Rules Check (DRC)
When `atlastag.kicad_pcb` exists:
```powershell
& "C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\kicad-cli.exe" pcb drc `
  --severity-all `
  --output "hardware/kicad/drc_report.txt" `
  "hardware/kicad/atlastag.kicad_pcb"
```
- Read `drc_report.txt` and report:
  - Clearance violations, track width errors, unrouted nets, keepout breaches.

### 4. Manual Hardware & RF Verification Checklist
Beyond automated CLI checks, manually inspect:
1. **RF Antenna Keepouts:** Verify ground plane is completely removed beneath and around the cellular and GNSS chip/patch antennas according to manufacturer app notes.
2. **RF Transmission Lines:** Verify 50Ω coplanar waveguide with ground has adequate via stitching along the trace edges.
3. **Power Tracks:** Verify VBAT, VBUS, and 3.3V battery/modem traces are sized adequately for 2A transmission burst currents (minimum 25–40 mil trace width or dedicated power polygon).
4. **Decoupling Placement:** Verify ceramic bypass capacitors are placed adjacent to power pins before vias to power planes.
5. **Cortex-M33 SWD & Debug:** Verify SWDIO, SWDCLK, GND, and VDD test points are physically accessible for pogo-pin programming.

### 5. Report Findings
Deliver a concise report:
- **ERC Status:** Error count, warning count, actionable fixes.
- **DRC Status:** Violation count, unrouted net count, actionable fixes.
- **RF & Power Layout Review:** Assessment of antenna keepouts, trace widths, and bypass caps.
- **Manufacturing Readiness:** State explicitly whether the board is ready for Gerber generation or blocked by open violations.
