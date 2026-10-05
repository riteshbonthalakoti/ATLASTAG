# Hardware Research Index

## 1. Cellular + GNSS Platforms
### Nordic nRF9151
- **Package:** LGA, 12.1 x 11.1 x 1.2 mm
- **Power:** PSM floor ~2.7 µA, eDRX (Cat-M1 @ 81.92s) ~18 µA
- **Features:** SiP with LTE-M/NB-IoT, GNSS, DECT NR+, Cortex-M33
- **Pros:** Extremely compact, low power, high integration.
- **Cons:** BGA/LGA footprint can be challenging for hobbyist/first-time custom PCBA.

### Quectel BG95-M3
- **Package:** LGA, 23.6 x 19.9 x 2.2 mm
- **Power:** PSM ~3 µA, idle ~27 mA
- **Pros:** Proven, widely used, AT command driven, good documentation.
- **Cons:** Larger physical footprint compared to Nordic/u-blox.

### u-blox SARA-R510M8S
- **Package:** LGA, 16 x 26 x 2.2 mm
- **Power:** PSM ~13-14 mA (with cyclic GNSS tracking). M8 GNSS engine prevents lowest power PSM when active.
- **Pros:** High-performance GNSS (M8), 5G-ready, robust security.
- **Cons:** Higher baseline power when GNSS is tracking, largest footprint in length.

### SIMCom SIM7080G
- **Package:** LCC+LGA, 17.6 x 15.7 x 2.3 mm
- **Power:** PSM ~3.2 µA, GNSS tracking ~52 mA
- **Pros:** Cost-effective, LCC footprint is easier to hand-solder/inspect.
- **Cons:** Higher active GNSS current.

## 2. Accelerometers (Wake-on-Motion)
- **Candidates:** ST LIS2DW12, ADI ADXL362, Bosch BMI160
- **Strategy:** Route INT pin to MCU. MCU sleeps in System OFF/Deep Sleep. Accelerometer runs autonomously at low ODR (sub-µA), pulls INT high on motion to wake MCU.

## 3. Power Management
- **Integrated PMIC vs Discrete:** 
  - PMICs (e.g., nPM1300 or SIMO PMICs) offer smaller footprint, lower IQ, and integrated battery charging/sequencing.
  - Discrete is cheaper for prototyping but takes more space and has higher IQ.
- **Recommendation:** SIMO PMIC or dedicated IoT PMIC for space and IQ optimization.

## 4. Storage
- **SPI NOR Flash:** Low power, sufficient for telemetry buffering.
- **microSD:** High power, mechanical footprint, overkill for small telemetry.

## 5. SIM / eSIM
- **Physical Nano SIM (4FF):** Easy for prototyping, takes up significant Z-height and PCB area.
- **eSIM (MFF2):** Solderable, robust, saves space.
- **iSIM:** Built into SoC (e.g., supported by newer Nordic chips). Smallest footprint.

## 6. Antennas
- **Virtual/Chip Antennas:** Ignion Virtual Antenna or standard chip antennas. Best for space. Require careful ground plane clearance and matching networks.
- **Ceramic Patch (GNSS):** Best performance, requires dedicated top-side area.

## 7. Dimensions
- **Target 1:** 40 x 30 x 10 mm (Aggressive, eSIM, chip antennas, small Li-Po)
- **Target 2:** 50 x 40 x 12 mm (Moderate, allows patch antenna, physical SIM)
