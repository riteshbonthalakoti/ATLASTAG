---
name: atlas-research
description: >-
  Investigate hardware components and technical candidates for AtlasTag using evidence from
  manufacturer datasheets, hardware integration manuals, and authorized distributor listings.
  Use when evaluating new ICs, antennas, sensors, or power management options.
---

# AtlasTag Hardware Candidate Research Procedure

Use this skill when investigating new components or evaluating technical options for the AtlasTag project.

---

## Operating Guidelines

- **Primary Sources Only:** Always base technical evaluations on official manufacturer datasheets, reference schematics, errata, and authorized distributor data sheets.
- **No Inventions:** Never fabricate part specifications, pinouts, price quotes, or availability.
- **Explicit Assumptions:** Clearly distinguish verified specifications from engineering estimates or vendor marketing claims.

---

## Step-by-Step Procedure

### 1. Define Requirements & Constraints
- Identify the exact functional role (e.g., Cellular Modem, GNSS Engine, Accelerometer, PMIC, Storage, Antenna).
- Identify system constraints:
  - Supply voltage ranges (e.g., Li-Po 3.0V–4.2V, 3.3V, 1.8V).
  - Quiescent current budget (< 10 µA system sleep target).
  - Physical package constraints (LGA, QFN, SOIC, passive geometry).
  - Host digital interfaces (I2C, SPI, UART, GPIO interrupts).

### 2. Retrieve Primary Documentation
- Locate the official datasheet, hardware integration manual, and reference layout guide from the manufacturer (Nordic Semiconductor, STMicroelectronics, Quectel, Winbond, etc.).
- Record the exact document revision, publication date, and source URL.

### 3. Extract Technical Specifications
Extract and verify:
- **Electrical Ratings:** Input voltage range, absolute maximum ratings, logic level compatibility.
- **Power Consumption:** Active current, sleep/PSM current, peak transmit current bursts.
- **Interfaces & Pinout:** Required digital buses, decoupling requirements, external passives, pull-up values.
- **RF Requirements:** Matched 50Ω transmission line requirements, external LNA needs, antenna keepout areas.
- **Thermal & Environmental:** Operating temperature range, moisture sensitivity level (MSL).

### 4. Verify Sourcing & Regional Compatibility
- For cellular/RF devices, verify band support for target deployment regions (LTE-M bands: B2, B4, B12, B28; NB-IoT bands).
- Verify stock availability and lead times on authorized distributors (Mouser India, DigiKey India, Robu.in, LCSC).
- Record unit pricing at 1-qty and 10-qty breaks in both USD ($) and INR (₹).

### 5. Document Findings
- Update `docs/research/RESEARCH_INDEX.md` with:
  - Component name, manufacturer, and exact MPN.
  - Package type and dimensions.
  - Power profiles (active and standby).
  - Key pros, cons, and implementation risks.
  - Primary source citations and documentation URLs.

### 6. Synthesize Summary & Identify Gaps
- Provide a concise summary to the user:
  - **Verified Facts:** What the datasheet conclusively proves.
  - **Uncertainties / Risks:** Errata, difficult assembly footprints (e.g., fine-pitch BGA/LGA), or missing RF data.
  - **Recommended Next Investigation:** Next testing or decision step needed.
