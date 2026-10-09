# AtlasTag — Detailed Bill of Materials (BOM)

> **Project:** AtlasTag (Hack Club Half Life)  
> **Target Tier:** Week 1 — Tier 3  
> **Exchange Rate:** **1.00 USD = ₹96.70 INR**  
> **Parts Funding Limit:** **$100.00 USD** (**₹9,670.00 INR**)  
> **Baseboard Prototype BOM (Week 1 Physical Build):** **$11.70 USD** / **₹1,131.41 INR**  
> **Estimated Full System BOM (Envisioned Complete Tracker):** **$44.25 USD** / **₹4,278.98 INR**  
> **Total Funding Headroom (Under Tier 3 Limit):** **$55.75 USD** / **₹5,391.02 INR**

---

## 1. BOM Reconciliation: Prototype Baseboard vs. Full System

| Scope | USD ($) | INR (₹ @ 96.70) | Description & Status |
| :--- | :--- | :--- | :--- |
| **Modular Baseboard Prototype (Week 1)** | **$11.70** | **₹1,131.41** | **Active Design (Reflected in `bom.csv` and KiCad baseboard design).** Solderable power management (MCP73831, AP2112K-3.3), offline SPI Flash (W25Q32), Nano-SIM socket, motion port, and mezzanine header. |
| **Envisioned Full Tracking System** | **$44.25** | **₹4,278.98** | **System Budget Projection.** Includes candidate cellular/GNSS platform ($25.40), PMIC ($3.45), accelerometer ($2.02), antennas ($3.83), battery ($3.00), and baseboard passives. Proves feasibility under the $100 budget cap. |

---

## 2. Modular Prototype Baseboard BOM (Active Week 1 Build)

*Directly matches `hardware/kicad/atlastag.kicad_sch`, `hardware/kicad/atlastag.kicad_pcb`, and `bom.csv`.*

| RefDes | Subsystem | Description | Manufacturer | Part Number (MPN) | Package / Footprint | Vendor Source | Unit Price (USD $) | Unit Price (INR ₹) | Qty | Total (USD $) | Total (INR ₹) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **U1** | Battery Charger | Linear CC/CV Li-Po Charger IC (212mA) | Microchip | **MCP73831T-2ACI/OT** | SOT-23-5 | Mouser | $0.50 | ₹48.35 | 1 | $0.50 | ₹48.35 |
| **U2** | Voltage Regulator | Ultra-Low-Dropout 3.3V 600mA LDO | Diodes Inc | **AP2112K-3.3TRG1** | SOT-23-5 | Mouser | $0.33 | ₹31.91 | 1 | $0.33 | ₹31.91 |
| **U3** | Telemetry Memory | 32Mb (4MB) High-Speed SPI NOR Flash | Winbond | **W25Q32JVSSIQ** | SOIC-8 (208 mil) | Evelta / Mouser | $1.20 | ₹116.04 | 1 | $1.20 | ₹116.04 |
| **J1** | 5V Power Port | 16-Pin USB-C Receptacle (5V Power) | Korean HRO / GCT | **TYPE-C-31-M-12** | Mid-Mount SMT | LCSC / Mouser | $0.45 | ₹43.52 | 1 | $0.45 | ₹43.52 |
| **J2** | Battery Port | 2-Pin 2.0mm Li-Po Header | JST | **S2B-PH-K-S** | Through-Hole 2.0mm | Robu.in / Mouser | $0.25 | ₹24.18 | 1 | $0.25 | ₹24.18 |
| **J3** | Motion Port | 5-Pin 2.54mm I2C Sensor Header | Generic | **PinHeader_1x05** | Through-Hole 2.54mm | Robu.in | $0.15 | ₹14.51 | 1 | $0.15 | ₹14.51 |
| **J4** | Modem Mezzanine | 16-Pin 2.54mm Mezzanine Interface | Generic | **PinHeader_2x08** | Through-Hole 2.54mm | Robu.in | $0.30 | ₹29.01 | 1 | $0.30 | ₹29.01 |
| **J5** | SIM Socket | Push-Pull Nano-SIM (4FF) Socket | GCT / Molex | **SIM8060-6-0-14-00** | SMT Perimeter | Mouser / LCSC | $1.62 | ₹156.65 | 1 | $1.62 | ₹156.65 |
| **C3** | Burst Bulk Cap | 100µF 10V Low-ESR Polymer/Tantalum | Panasonic / Kemet | **CP_EIA-3528-21** | EIA 3528-21 SMD | Mouser | $0.85 | ₹82.20 | 1 | $0.85 | ₹82.20 |
| **D1** | Charge LED | Red 0603 SMD LED | Everlight | **19-217/R6C-AL1M2VY/3T** | 0603 Metric | Mouser | $0.10 | ₹9.67 | 1 | $0.10 | ₹9.67 |
| **D2** | Power LED | Green 0603 SMD LED | Everlight | **19-217/GHC-YR1S2/3T** | 0603 Metric | Mouser | $0.10 | ₹9.67 | 1 | $0.10 | ₹9.67 |
| **SW1** | User Button | Tactile Push Switch | C&K | **PTS645Sx43SMTR92** | SMT Gull-Wing | Mouser | $0.35 | ₹33.85 | 1 | $0.35 | ₹33.85 |
| **BAT1**| Battery | 3.7V 500mAh 1S Li-Po Cell (with PCM) | WLY / Robu.in | **WLY902030** | Prismatic w/ Leads | Robu.in | $3.00 | ₹290.10 | 1 | $3.00 | ₹290.10 |
| **PASS**| Passives Kit | 0603 Resistors (R1–R15) & Caps (C1–C8) | Yageo / Murata | **Generic 0603 Kit** | 0603 Metric | Robu / Mouser | $2.50 | ₹241.75 | 1 | $2.50 | ₹241.75 |
| **TOTAL**| | **Modular Baseboard Prototype Subtotal** | | | | | | | | **$11.70** | **₹1,131.41** |

---

## 3. Envisioned Full System BOM (Candidate Monolithic SiP Concept)

*Maintained to verify that the complete standalone tracker fits under the $100 Half Life budget cap.*

| RefDes | Subsystem | Description | Manufacturer | Part Number (MPN) | Footprint / Package | Vendor Source | Unit Price (USD $) | Unit Price (INR ₹) | Qty | Total (USD $) | Total (INR ₹) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **U1** | Cellular + GNSS SoC | LTE-M / NB-IoT SiP with Cortex-M33 & GNSS | Nordic Semi | **NRF9151-LACA-R** | LGA-114 (12.1×11.1mm) | Mouser India | $25.40 | ₹2,456.18 | 1 | $25.40 | ₹2,456.18 |
| **U2** | Power Management | Smart PMIC with CC/CV Li-Po Charger | Nordic Semi | **nPM1300-QEAA-R** | QFN-32 (5.0×5.0mm) | Mouser India | $3.45 | ₹333.62 | 1 | $3.45 | ₹333.62 |
| **U3** | Motion Sensor | Ultra-low-power 3-axis accelerometer | STMicro | **LIS2DW12TR** | LGA-12 (2.0×2.0mm) | Mouser India | $2.02 | ₹195.33 | 1 | $2.02 | ₹195.33 |
| **U4** | Telemetry Memory | 32Mb SPI NOR Flash Telemetry Queue | Winbond | **W25Q32JVSSIQ** | SOIC-8 (208 mil) | Mouser / Evelta | $1.20 | ₹116.04 | 1 | $1.20 | ₹116.04 |
| **ANT1**| Cellular Antenna | RUN mXTEND™ Wideband Virtual Antenna | Ignion | **NN02-224** | SMD (12.0×3.0mm) | DigiKey India | $1.35 | ₹130.55 | 1 | $1.35 | ₹130.55 |
| **ANT2**| GNSS Antenna | 1575.42 MHz Ceramic Patch Antenna | Abracon | **APAE1575R2540BBDB1-T** | SMD Patch (25×25×4mm) | DigiKey India | $2.48 | ₹239.82 | 1 | $2.48 | ₹239.82 |
| **J1** | Charge & USB Port | 16-Pin USB Type-C Receptacle | GCT | **USB4105-GF-A** | Surface Mount | Mouser India | $0.90 | ₹87.03 | 1 | $0.90 | ₹87.03 |
| **J2** | SIM Interface | Push-Pull Nano-SIM (4FF) Socket | Molex | **104224-0820** | SMT (12.1×11.5mm) | Mouser India | $1.62 | ₹156.65 | 1 | $1.62 | ₹156.65 |
| **BAT1**| Battery | 3.7V 500mAh 1S Li-Po Battery with PCM | Robu.in / WLY | **WLY902030** | Prismatic w/ Leads | Robu.in | $3.00 | ₹290.10 | 1 | $3.00 | ₹290.10 |
| **PASS**| Passive Kit | Decoupling caps, pull-ups, RF matching | Yageo / Murata | **Generic Passives Kit** | 0402 / 0603 | Robu / Mouser | $2.83 | ₹273.66 | 1 | $2.83 | ₹273.66 |
| **TOTAL**| | **Envisioned Full System Subtotal** | | | | | | | | **$44.25** | **₹4,278.98** |

---

## 4. Half Life Tier 3 Budget Analysis

| Parameter | Value in USD ($) | Value in INR (₹ @ 96.70) | Allocation Status |
| :--- | :--- | :--- | :--- |
| **Hack Club Half Life Tier 3 Parts Funding Cap** | **$100.00** | **₹9,670.00** | Maximum Allowed Funding |
| **AtlasTag Envisioned Core System BOM** | **$44.25** | **₹4,278.98** | Full Tracker Cost Projection |
| **Estimated Custom PCB Fab (5 pcs @ JLCPCB/LionCircuits)** | **$15.00** | **₹1,450.50** | Budgeted Manufacturing Reserve |
| **SMD Stencil & Solder Consumables** | **$8.00** | **₹773.60** | Budgeted Tooling Reserve |
| **Remaining Contingency Margin** | **$32.75** | **₹3,166.92** | Unallocated Buffer |
| **Total Projected Project Expenditure** | **$67.25** | **₹6,503.08** | **Comfortably within $100 Cap ($32.75 / ₹3,166.92 Headroom)** |
