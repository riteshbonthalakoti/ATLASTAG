/**
 * @file main.c
 * @brief AtlasTag Firmware — Architectural Conceptual Stub (Week 1 Checkpoint)
 * @project Hack Club Half Life (Tier 3)
 * @status STUB / ARCHITECTURAL MOCKUP — NOT PRODUCTION DRIVERS
 * @details This file provides an architectural reference model for state machine
 *          transitions and battery voltage threshold calculations. It uses mock
 *          data (hardcoded ADC sample values) and standard C library output.
 *          Target MCU hardware drivers (I2C for motion, SPI for NOR Flash,
 *          ADC HAL for battery sensing, UART for modem AT commands) will be
 *          implemented once the primary Cellular/GNSS platform and host MCU
 *          architecture are finalized.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* Hardware Configuration Constants */
#define VBAT_DIVIDER_RATIO      2.0f      /* 1M / 1M resistive divider */
#define ADC_VREF_MV             3300      /* 3.3V System ADC reference */
#define BATTERY_MIN_SAFE_MV     3300      /* Cutoff threshold to prevent brownouts */
#define BATTERY_FULL_MV         4200      /* 1S Li-Po fully charged */

/* Operational State Definitions */
typedef enum {
    STATE_DEEP_SLEEP = 0,
    STATE_WAKE_MOTION,
    STATE_SAMPLE_BATTERY,
    STATE_QUEUE_TELEMETRY,
    STATE_MODEM_TX_BURST,
    STATE_POWER_ERROR
} system_state_t;

/* Telemetry Record Structure (stored in SPI Flash queue) */
typedef struct {
    uint32_t timestamp;
    uint16_t vbat_mv;
    int16_t  accel_x;
    int16_t  accel_y;
    int16_t  accel_z;
    uint8_t  status_flags;
} __attribute__((packed)) telemetry_record_t;

/* Global System State */
static system_state_t g_system_state = STATE_DEEP_SLEEP;

/**
 * @brief Convert raw ADC counts to battery millivolts
 */
uint16_t atlastag_read_battery_mv(uint16_t raw_adc, uint16_t adc_resolution) {
    if (adc_resolution == 0) return 0;
    float adc_voltage = ((float)raw_adc / (float)adc_resolution) * (float)ADC_VREF_MV;
    return (uint16_t)(adc_voltage * VBAT_DIVIDER_RATIO);
}

/**
 * @brief Verify battery voltage is sufficient for cellular RF burst
 */
bool atlastag_is_battery_safe(uint16_t vbat_mv) {
    return (vbat_mv >= BATTERY_MIN_SAFE_MV);
}

/**
 * @brief Main execution entry point
 */
int main(void) {
    printf("[AtlasTag] Booting Modular Prototype Baseboard Firmware\n");
    printf("[AtlasTag] Hardware Version: v0.1.0-draft (Week 1 Checkpoint)\n");
    
    /* Initialize peripherals: I2C (Motion), SPI (NOR Flash), UART (Modem), ADC */
    g_system_state = STATE_SAMPLE_BATTERY;
    
    /* NOTE: Simulated ADC reading (2600 counts on 12-bit ADC / 4095 max, equivalent to ~4.18V).
     * Hardware ADC driver integration is pending target host MCU selection. */
    uint16_t current_vbat_mv = atlastag_read_battery_mv(2600, 4095);
    printf("[AtlasTag] Battery Voltage (Simulated): %u mV\n", current_vbat_mv);
    
    if (!atlastag_is_battery_safe(current_vbat_mv)) {
        printf("[AtlasTag] WARNING: Low battery. Cellular Tx inhibited to prevent brownout.\n");
        g_system_state = STATE_POWER_ERROR;
        return -1;
    }
    
    printf("[AtlasTag] Entering motion-triggered sleep mode.\n");
    g_system_state = STATE_DEEP_SLEEP;
    
    return 0;
}
