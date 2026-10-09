# Hardware Decision Log

## Decisions

| Date | Topic | Options Considered | Decision | Justification | Status |
|------|-------|--------------------|----------|---------------|--------|
| 2026-10-09 | Cellular/GNSS Platform | nRF9151-LACA-R, BG95-M3, SIM7080G | [PENDING] | Sourced trade study completed. With 'soldering iron only', nRF9151 (LGA-114) is impossible unless low-cost PTC hot plate (~₹450 INR) or local repair shop rework is approved. SIM7080G LCC is hand-solderable (via bottom via for center pad), but requires discrete MCU, level shifter, and external GNSS LNA. BG95-M3 has 3.3V brownout risk. Indian deployment requires NB-IoT (B3/B5/B8). Decision kept OPEN pending tooling selection and SIM/carrier verification. | OPEN |
| YYYY-MM-DD | Accelerometer | LIS2DW12, ADXL362 | LIS2DW12 (Tentative) | Excellent power profile and built-in wake features. | OPEN |
| YYYY-MM-DD | Power Management | PMIC vs Discrete | PMIC | Space constraint and ultra-low IQ requirement for PSM. | OPEN |
| YYYY-MM-DD | Storage | SPI NOR vs microSD | SPI NOR | Lower power, smaller footprint. | OPEN |
| YYYY-MM-DD | SIM Configuration | Physical (4FF) vs eSIM (MFF2) | [PENDING] | Physical is easier for testing, eSIM saves critical space. | OPEN |
| YYYY-MM-DD | Antenna Strategy | Chip/Virtual vs Ceramic Patch | [PENDING] | Space vs GNSS performance tradeoff. | OPEN |
| YYYY-MM-DD | Charging Strategy | USB-C vs Pogo pins | [PENDING] | USB-C is universal but takes space and needs sealing. | OPEN |
