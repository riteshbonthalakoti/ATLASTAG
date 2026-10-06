# System Architecture: AtlasTag

*Status: DRAFT (Under Research Phase)*

---

## Visual Architecture & Flow

A simple, single-view diagram showing how AtlasTag tracks assets and delivers location updates to the user.

```mermaid
flowchart LR
    %% Main Pipeline
    Motion["🚶 Motion Sensor<br/><b>(Detects Movement)</b>"]
    -->|"1. Wakes up"| Brain["🧠 Microcontroller<br/><b>(Main Brain)</b>"]

    GPS["🛰️ GPS Satellites<br/><b>(Finds Coordinates)</b>"]
    -->|"2. Sends location"| Brain

    Brain
    -->|"3. Formats message"| Modem["📶 Cellular Modem<br/><b>(4G / LTE-M)</b>"]

    Modem
    -->|"4. Uploads over internet"| CloudApp["📱 User's Phone<br/><b>(Live Map & Alerts)</b>"]

    %% Backup Storage
    Modem -.->|"No signal? (Backup)"| Storage["💾 Flash Memory<br/><b>(Saves offline data)</b>"]
    Storage -.->|"Upload when back online"| Modem

    %% Power
    Power["🔋 Battery & Charger<br/><b>(Powers everything)</b>"]
    ==>|"Continuous Power"| Brain

    %% High-contrast, clean styling
    style Motion fill:#E8F5E9,stroke:#2E7D32,stroke-width:2px,color:#1B5E20
    style GPS fill:#E1F5FE,stroke:#0288D1,stroke-width:2px,color:#01579b
    style Brain fill:#EDE7F6,stroke:#512DA8,stroke-width:2px,color:#311B92
    style Modem fill:#FFF3E0,stroke:#E65100,stroke-width:2px,color:#BF360C
    style CloudApp fill:#FCE4EC,stroke:#C2185B,stroke-width:2px,color:#880E4F
    style Storage fill:#FFFDE7,stroke:#FBC02D,stroke-width:2px,color:#F57F17
    style Power fill:#ECEFF1,stroke:#455A64,stroke-width:2px,color:#263238
```

---

## How It Works (The 5-Step Flow)

1. **Sleeps to Save Battery:** Most of the time, the device stays asleep to last months on a small battery.
2. **Wakes Up on Movement:** When someone moves the tracked object, the motion sensor detects it and immediately wakes the brain (microcontroller).
3. **Finds Its Location:** The GPS receiver powers on, connects to satellites, and locks the exact coordinates (latitude and longitude). If indoors, it uses nearby cellular towers as a fallback.
4. **Sends Location to Your Phone:** The cellular modem wakes up and sends the location packet over 4G LTE-M to the cloud, updating the mobile app in real time.
5. **Offline Safety Net:** If the device is out of cellular coverage (e.g., in a basement or shipping container), it saves the location history to internal flash memory and uploads everything automatically once signal returns.

---

## Power System
- **Battery:** 3.7V rechargeable Li-Po battery (~400–800 mAh).
- **Charging:** Standard USB-C charging with built-in battery management (PMIC).
- **Efficiency:** Turns off GPS and cellular antennas between updates to achieve under 10 µA standby current.

---

## Location Strategy
- **Outdoor:** High-accuracy GPS / GNSS (< 5 meters).
- **Indoor Fallback:** Cellular tower triangulation if satellite signals are blocked.

---

## Sleep & Wake Triggers
- **Motion Trigger:** Wakes immediately when movement or vibration is detected.
- **Heartbeat Timer:** Wakes periodically (e.g., once every 12 hours) even if stationary to report battery status and check in.
- **Charger Trigger:** Wakes automatically when plugged into USB-C.

---

## Hardware Component Summary

| Role | Component Candidate | Purpose |
| :--- | :--- | :--- |
| **Main Brain & Modem** | Nordic nRF9151 / Quectel BG95 | Runs device logic, reads GPS, connects to 4G LTE-M |
| **Motion Sensor** | ST LIS2DW12 | Ultra-low power accelerometer that detects motion |
| **Power Manager (PMIC)** | Nordic nPM1300 / Discrete PMIC | Safely charges battery via USB-C and manages power rails |
| **Offline Memory** | SPI NOR Flash | Stores unsent location records when off-grid |
| **SIM Card** | Solderable eSIM / Nano-SIM | Provides global cellular network connectivity |
