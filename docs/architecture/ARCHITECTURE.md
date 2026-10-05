# System Architecture: AtlasTag

*Status: DRAFT (Under Research Phase)*

## System Block Diagram
MCU/Modem core <--> I2C <--> Accelerometer (INT mapped to MCU GPIO)
MCU/Modem core <--> SPI <--> NOR Flash
PMIC <--> Battery / USB-C
PMIC <--> System Power Rails
Antenna <--> RF matching <--> Modem

## Power-Tree Concept
1. **Source:** 3.7V Li-Po battery (target ~400-800 mAh) + USB-C 5V input.
2. **Charging:** Integrated into PMIC, standard CC/CV Li-Po charge curve.
3. **Regulation:** High-efficiency buck-boost or SIMO PMIC generating:
   - 3.3V / 1.8V for Modem & MCU
   - 1.8V for Sensors / Storage
4. **Quiescent Current:** Target overall system sleep current < 10 µA.

## Data-Flow Diagram
1. Accelerometer triggers INT on motion.
2. MCU wakes from deep sleep, powers on GNSS.
3. GNSS acquires fix (coordinates, timestamp, speed).
4. MCU powers on Cellular Modem, connects to LTE-M.
5. MCU sends payload via MQTT/CoAP.
6. If connection fails, payload is serialized and written to SPI NOR Flash.

## Location-Strategy Concept
- **Primary:** GNSS for high accuracy outdoors.
- **Secondary:** Cell-tower location fallback if GNSS fix fails (indoors/urban canyon) to save battery.

## Sleep/Wake Concept
- **Deep Sleep:** Modem in PSM (Power Saving Mode), MCU in System OFF/Deep Sleep. Accelerometer running.
- **Wake:** Triggered by Accelerometer INT or RTC Timer (e.g., every 12 hours for heartbeat).

## Telemetry Concept
Payload structure: `[Timestamp, Lat, Lon, Alt, Speed, Bat_mV, Fix_Type]`

## Security Concept
- Hardware Root of Trust / TrustZone (if using nRF9151).
- TLS/DTLS for payload encryption over LTE-M.

## Major Interfaces
- **I2C:** Accelerometer, PMIC (if programmable)
- **SPI:** NOR Flash
- **UART:** Debug/Console
- **SWD / JTAG:** Firmware programming
