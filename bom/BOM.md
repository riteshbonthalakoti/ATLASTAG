# AtlasTag — Detailed Bill of Materials (BOM)

> **Project:** AtlasTag (Hack Club Half Life)  
> **Target Tier:** Week 1 — Tier 3  
> **Parts Funding Limit:** **$100.00 USD** (~**₹8,350 INR** @ 1 USD ≈ ₹83.50)  
> **Estimated Unit Cost (Primary Build):** **$44.65 USD** / **₹3,728 INR**  
> **Remaining Budget Headroom:** **$55.35 USD** / **₹4,622 INR** (Available for PCB fabrication & assembly spares)

---

## 1. Primary Hardware BOM (Production Build)

Real-time distributor pricing referenced from authorized Indian distributors (Mouser India, DigiKey India, Robu.in) and global distributors (Mouser US, DigiKey, LCSC) as of October 2026.

| RefDes | Subsystem | Description | Manufacturer | Part Number (MPN) | Footprint / Package | Indian Source | Unit Price (INR ₹) | Global Source | Unit Price (USD $) | Qty | Total (INR ₹) | Total (USD $) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **U1** | Cellular + GNSS SoC | LTE-M / NB-IoT SiP with Arm Cortex-M33 & GNSS | Nordic Semiconductor | **NRF9151-LACA-R** | LGA-114 (12.1×11.1mm) | Mouser India | ₹2,138.19 | Mouser / DigiKey | $25.40 | 1 | ₹2,138.19 | $25.40 |
| **U2** | Power Management | Smart PMIC with CC/CV Li-Po Charger & Dual Buck | Nordic Semiconductor | **nPM1300-QEAA-R** | QFN-32 (5.0×5.0mm) | Mouser India | ₹291.40 | Mouser / DigiKey | $3.45 | 1 | ₹291.40 | $3.45 |
| **U3** | Motion Sensor | Ultra-low-power 3-axis accelerometer (<1µA sleep) | STMicroelectronics | **LIS2DW12TR** | LGA-12 (2.0×2.0mm) | Mouser India | ₹171.02 | Mouser / DigiKey | $2.02 | 1 | ₹171.02 | $2.02 |
| **U4** | Offline Telemetry Memory | 32Mb (4MB) High-Speed SPI NOR Flash | Winbond | **W25Q32JVSSIQ** | SOIC-8 (208 mil) | Evelta / Mouser | ₹102.00 | Mouser / LCSC | $1.20 | 1 | ₹102.00 | $1.20 |
| **ANT1** | Cellular Antenna | RUN mXTEND™ Wideband Cellular Virtual Antenna | Ignion | **NN02-224** | SMD (12.0×3.0mm) | DigiKey India | ₹115.00 | DigiKey / Mouser | $1.35 | 1 | ₹115.00 | $1.35 |
| **ANT2** | GNSS Antenna | 1575.42 MHz Ceramic Patch Antenna / Chip | Abracon | **APAE1575R2540BBDB1-T** | SMD Patch (25×25×4mm) | DigiKey India | ₹209.25 | DigiKey / Mouser | $2.48 | 1 | ₹209.25 | $2.48 |
| **J1** | Charge & USB Port | 16-Pin USB-C Receptacle (5V Power + USB 2.0) | GCT | **USB4105-GF-A** | Surface Mount / Mid-mount | Mouser India | ₹76.43 | Mouser / LCSC | $0.90 | 1 | ₹76.43 | $0.90 |
| **J2** | SIM Interface | Push-Pull Nano-SIM (4FF) Socket | Molex | **104224-0820** | SMT (12.1×11.5mm) | Mouser India | ₹137.58 | Mouser / DigiKey | $1.62 | 1 | ₹137.58 | $1.62 |
| **BAT1** | Battery | 3.7V 500mAh 1S Li-Po Battery with PCM Protection | Robu.in / WLY | **WLY902030** | Prismatic w/ Leads | Robu.in | ₹249.00 | Robu / Adafruit | $3.00 | 1 | ₹249.00 | $3.00 |
| **PASS** | Passive Components | Decoupling caps (0402), pull-ups, RF matching, TVS diodes | Yageo / Murata | **Generic Passives Kit** | 0402 / 0603 | Robu / Evelta / Mouser | ₹238.00 | LCSC / DigiKey | $2.83 | 1 | ₹238.00 | $2.83 |
| **TOTAL** | | **Primary Production Bill of Materials** | | | | | | | | | **₹3,727.87** | **$44.65** |

---

## 2. Component Alternatives & Evaluation Options

These candidate components were evaluated during architecture research for alternate trade-offs in soldering ease, module footprint, or form factor.

| Category | Component Candidate | Manufacturer | Part Number | Indian Source & Price (INR) | Global Source & Price (USD) | Trade-off / Notes |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Cellular Alt 1** | BG95-M3 LTE-M/NB-IoT Module | Quectel | BG95-M3 | Mouser.in: **₹1,750.00** | Mouser: **$21.00** | Hand-solderable LGA, requires discrete host MCU |
| **Cellular Alt 2** | SIM7080G Cellular Module | SIMCom | SIM7080G | Robu.in: **₹1,580.00** | LCSC: **$18.50** | Cost-effective LCC package; higher active GNSS current |
| **Storage Alt** | 64Mb (8MB) SPI NOR Flash | Winbond | W25Q64JVSSIQ | Mouser.in: **₹249.72** | Mouser: **$2.95** | 2x storage depth for extended disconnected logs |
| **GNSS Ant Alt** | Miniature SMD GPS Chip Antenna | Johanson | 1575AT43A0040001E | Mouser.in: **₹89.81** | Mouser: **$1.06** | Ultra-compact 7×2mm footprint; lower passive gain than patch |
| **SIM Alt** | Industrial eSIM (MFF2) | STMicroelectronics | ST4SI2M0020TPIFW | Mouser.in: **₹380.17** | Mouser: **$4.50** | Solderable DFN-8; eliminates mechanical socket, requires eSIM profile |

---

## 3. Sourcing Strategy & Purchasing in India

### Indian Sourcing Channels:
1. **Mouser Electronics India (`mouser.in`):**
   - **Local Currency:** Invoices in **INR** with standard 18% GST input credit support (`GSTIN`).
   - **Shipping:** Free delivery to Indian addresses for orders exceeding **₹4,000 INR** (approx. $50 USD). Combining the SiP, PMIC, accelerometer, and connectors into one Mouser order easily qualifies for free door-to-door delivery with customs cleared.
2. **DigiKey India (`digikey.in`):**
   - **Local Currency:** Prices quoted in INR; free shipping on orders over **₹7,000 INR**. Used for specialized RF antennas (Ignion and Abracon).
3. **Robu.in (Domestic Electronics Distributor — Pune, India):**
   - **Fast Domestic Delivery:** 2 to 4 days across India via BlueDart/DTDC.
   - **Li-Po Batteries:** Crucial for battery procurement. International air shipping of raw Li-Po cells from Mouser/DigiKey is strictly regulated or restricted under IATA Dangerous Goods regulations into India. Procuring the 3.7V 500mAh Li-Po cell domestically via Robu.in avoids international shipping roadblocks.
4. **Quartz Components / Evelta:**
   - Excellent domestic sources for Winbond SPI NOR flash ICs, passive kits, and test points.

---

## 4. Half Life Tier 3 Budget Analysis

| Parameter | Value in USD | Value in INR (1 USD ≈ ₹83.50) | Status |
| :--- | :--- | :--- | :--- |
| **Hack Club Half Life Funding Limit** | **$100.00** | **₹8,350.00** | Allocated |
| **AtlasTag Core BOM Cost** | **$44.65** | **₹3,727.87** | Committed |
| **Estimated Custom PCB Fab (5 pcs @ JLCPCB/LionCircuits)** | **$15.00** | **₹1,250.00** | Budgeted |
| **SMD Stencil & Solder Paste** | **$8.00** | **₹668.00** | Budgeted |
| **Remaining Contingency Reserve** | **$32.35** | **₹2,704.13** | Buffer |
| **Total Project Expenditure** | **$67.65** | **₹5,645.87** | **Within 100% Budget ($32.35 Under)** |
