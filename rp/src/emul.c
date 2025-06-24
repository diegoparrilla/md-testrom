/**
 * File: emul.c
 * Author: Diego Parrilla Santamaría
 * Date: February 2025
 * Copyright: 2025 - GOODDATA LABS
 * Description: Template code for the core emulation
 */

#include "emul.h"

// inclusw in the C file to avoid multiple definitions
#include "target_firmware.h"  // Include the target firmware binary

void emul_start() {
  // The standard procedure has been simplified to focus only on ROM emulation

  // As a rule of thumb, the remote device (the computer) driver code must
  // be copied to the RAM of the host device where the emulation will take
  // place.
  // The code is stored as an array in the target_firmware.h file
  //
  // Copy the terminal firmware to RAM
  DPRINTF("Firmware length: %u words\n", target_firmware_length);
  COPY_FIRMWARE_TO_RAM((uint16_t *)target_firmware, target_firmware_length);

  // Initialize the terminal emulator PIO programs
  // Only ROM emulation is needed.
  init_romemul(NULL, NULL, false);

  // Blink on
#ifdef BLINK_H
  blink_on();
#endif

  // Configure the SELECT button
  select_configure();

  // Start the main loop
  // Extremely simple loop that waits for the SELECT button to be pressed
  DPRINTF("Start the app loop here\n");
  while (!select_detectPush()) {
    tight_loop_contents();
    sleep_ms(SELECT_LOOP_DELAY);
  }
  DPRINTF("Waiting for SELECT button to be released\n");
  while (select_detectPush()) {
    tight_loop_contents();
    sleep_ms(SELECT_LOOP_DELAY);
  }
  // Jump to the booster app
  DPRINTF("Jumping to the booster app...\n");
  settings_put_string(gconfig_getContext(), PARAM_BOOT_FEATURE, "BOOSTER");
  settings_save(gconfig_getContext(), true);
  sleep_ms(SLEEP_LOOP_MS);
  // Reset the device and jump to the booster app
  DPRINTF("Jumping to the booster app...\n");
  reset_jump_to_booster();
}