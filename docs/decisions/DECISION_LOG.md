# Hardware Decision Log

## Decisions

| Date | Topic | Options Considered | Decision | Justification | Status |
|------|-------|--------------------|----------|---------------|--------|
| YYYY-MM-DD | Cellular/GNSS Platform | nRF9151, BG95-M3, SARA-R510M8S, SIM7080G | [PENDING] | Need to weigh ease of soldering (LCC vs LGA) vs physical footprint and firmware ecosystem. | OPEN |
| YYYY-MM-DD | Accelerometer | LIS2DW12, ADXL362 | LIS2DW12 (Tentative) | Excellent power profile and built-in wake features. | OPEN |
| YYYY-MM-DD | Power Management | PMIC vs Discrete | PMIC | Space constraint and ultra-low IQ requirement for PSM. | OPEN |
| YYYY-MM-DD | Storage | SPI NOR vs microSD | SPI NOR | Lower power, smaller footprint. | OPEN |
| YYYY-MM-DD | SIM Configuration | Physical (4FF) vs eSIM (MFF2) | [PENDING] | Physical is easier for testing, eSIM saves critical space. | OPEN |
| YYYY-MM-DD | Antenna Strategy | Chip/Virtual vs Ceramic Patch | [PENDING] | Space vs GNSS performance tradeoff. | OPEN |
| YYYY-MM-DD | Charging Strategy | USB-C vs Pogo pins | [PENDING] | USB-C is universal but takes space and needs sealing. | OPEN |
