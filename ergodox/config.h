// https://docs.qmk.fm/platformdev_rp2040

#pragma once // Start of header
#define MASTER_LEFT                 // which side is plugged in
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode

#define SERIAL_TX_PIN 0  // Set your TX pin
#define SERIAL_RX_PIN 1  // Set your RX pin

#define RGBLIGHT_SLEEP /* If defined, the RGB lighting will be switched off when the host goes to sleep */

#define SPLIT_TRANSPORT_SYNC_ENABLE
