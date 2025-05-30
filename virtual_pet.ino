#include <Arduino.h>
#include <U8g2lib.h>
#include <avr/pgmspace.h>

// OLED ekran 270 derece döndürülmüş
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R3, /* reset=*/ U8X8_PIN_NONE);

// 64x64 bar emoji ve pet bitmap'leri
const uint8_t bar_bitmap[] PROGMEM = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x03,0x00,0x00,0x00,0x00,0x00,
 0x00,0x9e,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x06,0x00,0x00,0x00,0x00,
 0x00,0x00,0xfe,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0xf2,0x05,0x00,0x00,0x00,
 0x00,0x00,0x00,0xe6,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xcc,0x03,0x00,0x00,
 0x00,0x00,0x00,0x00,0xd8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
 0xa0,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x02,0x00,0x00,0x00,0x00,0x00,
 0x00,0x10,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x01,0x00,0x00,0x00,0x00,
 0x00,0x00,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0xf8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x02,
 0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0xb2,
 0x05,0x00,0x00,0x00,0x00,0x00,0x00,0xb2,0x05,0x00,0x00,0x00,0x00,0x00,0x00,
 0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x05,0x00,0x00,0x00,0x00,0x00,
 0x00,0xe2,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x02,0x00,0x00,0x00,0x00,
 0x00,0x00,0xf8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x04,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x02,0x00,
 0x00,0x00,0x00,0x00,0x00,0x1e,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x04,
 0x00,0x00,0x00,0x00,0x00,0x00,0x84,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x48,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00 };

const uint8_t pet_normal[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,
 0x00,0x00,0x00,0xc0,0x3f,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0x3f,0x00,0x00,
 0xff,0x03,0x00,0x00,0xc0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,0x3f,0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,
 0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,
 0x00,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,
 0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0xff,0x03,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_happy[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,
 0x00,0x00,0x00,0xc0,0x3f,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0x3f,0x00,0x00,
 0xff,0x03,0x00,0x00,0xc0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,0x3f,0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,
 0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,
 0x00,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,
 0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0x3f,0xf0,
 0xff,0xff,0x03,0x00,0xff,0xff,0x3f,0xf0,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_sad[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,
 0x00,0x00,0x00,0xc0,0x3f,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0x3f,0x00,0x00,
 0xff,0x03,0x00,0x00,0xc0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,
 0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0x3f,0x00,0x00,0xff,0xc1,0xfb,0x7f,0x8f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x01,0xf8,0x7f,0x80,0x3f,0x00,0x00,0xff,0xe7,0xff,0xf0,0xe7,0x3f,0x00,
 0x00,0xff,0xe7,0xff,0xf0,0xe7,0x3f,0x00,0xfc,0xff,0xf7,0xff,0xff,0xef,0xff,
 0x3f,0xfc,0xff,0xf7,0xff,0xff,0xef,0xff,0x3f,0x00,0xff,0xff,0x3f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x3f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,
 0xff,0xff,0x03,0x00,0xff,0xff,0x0f,0xc0,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_boring[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,
 0x00,0x00,0x00,0xc0,0x3f,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0x3f,0x00,0x00,
 0xff,0x03,0x00,0x00,0xc0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,
 0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,
 0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0xff,0x03,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_sleep1[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0xfe,0x01,0x3f,0x00,0x00,0xfc,0x00,0x00,0xfe,0x01,0x3f,0x00,0x00,0xfc,
 0x00,0x00,0x80,0xc1,0x3f,0x00,0x00,0xff,0x03,0x00,0x80,0xc1,0x3f,0x00,0x00,
 0xff,0x03,0x00,0x60,0xc0,0xff,0x00,0x00,0xff,0x03,0x00,0x60,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x00,0x18,0xf0,0xff,0x00,0x00,0xff,0x03,0x00,0x18,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x00,0xfe,0xf1,0xff,0x03,0xc0,0xff,0x0f,0x00,0xfe,0xf1,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,
 0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,
 0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xf0,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xf0,0xff,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0xff,0x03,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_sleep2[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0xfe,0x01,0x3f,0x00,0x00,0xfc,0x00,0x00,0xfe,0x01,0x3f,0xf0,0x0f,0xfc,
 0x00,0x00,0x80,0xc1,0x3f,0xf0,0x0f,0xff,0x03,0x00,0x80,0xc1,0x3f,0x00,0x0c,
 0xff,0x03,0x00,0x60,0xc0,0xff,0x00,0x0c,0xff,0x03,0x00,0x60,0xc0,0xff,0x00,
 0x03,0xff,0x03,0x00,0x18,0xf0,0xff,0x00,0x03,0xff,0x03,0x00,0x18,0xf0,0xff,
 0xc0,0x00,0xff,0x03,0x00,0xfe,0xf1,0xff,0xc3,0xc0,0xff,0x0f,0x00,0xfe,0xf1,
 0xff,0xf3,0xcf,0xff,0x0f,0x00,0x00,0xfc,0xff,0xf3,0xcf,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,
 0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,
 0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xf0,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xf0,0xff,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xf3,
 0xff,0xff,0x03,0x00,0xff,0xff,0xff,0xf3,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_sleep3[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0xfe,0x01,0x3f,0x00,0x00,0xfc,0x80,0x7f,0xfe,0x01,0x3f,0xf0,0x0f,0xfc,
 0x80,0x7f,0x80,0xc1,0x3f,0xf0,0x0f,0xff,0x03,0x60,0x80,0xc1,0x3f,0x00,0x0c,
 0xff,0x03,0x60,0x60,0xc0,0xff,0x00,0x0c,0xff,0x03,0x18,0x60,0xc0,0xff,0x00,
 0x03,0xff,0x03,0x18,0x18,0xf0,0xff,0x00,0x03,0xff,0x03,0x06,0x18,0xf0,0xff,
 0xc0,0x00,0xff,0x03,0x06,0xfe,0xf1,0xff,0xc3,0xc0,0xff,0x8f,0x7f,0xfe,0xf1,
 0xff,0xf3,0xcf,0xff,0x8f,0x7f,0x00,0xfc,0xff,0xf3,0xcf,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,
 0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,
 0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,
 0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xf0,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xf0,0xff,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xf3,
 0xff,0xff,0x03,0x00,0xff,0xff,0xff,0xf3,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xf3,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xf3,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_warning1[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,
 0x00,0x00,0x00,0xc0,0x3f,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0x3f,0x00,0x00,
 0xff,0x03,0x00,0x00,0xc0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x00,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,0x3f,0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,
 0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,
 0x00,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,
 0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x3f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x3f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,
 0xff,0xff,0x03,0x00,0xff,0xff,0x0f,0xc0,0xff,0xff,0x03,0xfc,0xf0,0xff,0x3f,
 0xf0,0xff,0x0f,0x00,0xfc,0xf0,0xff,0x3f,0xf0,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_warning2[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x00,0x00,0xfc,0x00,0x0e,0x00,0x00,0x3f,0x00,0x00,0xfc,
 0x00,0x0e,0x00,0xc0,0x3f,0x00,0x00,0xff,0x03,0x0e,0x00,0xc0,0x3f,0x00,0x00,
 0xff,0x03,0x0e,0x00,0xc0,0xff,0x00,0x00,0xff,0x03,0x0e,0x00,0xc0,0xff,0x00,
 0x00,0xff,0x03,0x0e,0x00,0xf0,0xff,0x00,0x00,0xff,0x03,0x0e,0x00,0xf0,0xff,
 0x00,0x00,0xff,0x03,0x0e,0x00,0xf0,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x0e,0x00,
 0xfc,0xff,0x03,0xc0,0xff,0x0f,0x0e,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x0e,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,0x3f,0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,
 0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,
 0x00,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,
 0x00,0xff,0x0f,0xfc,0xf0,0xc0,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x3f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x3f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,
 0xff,0xff,0x03,0x00,0xff,0xff,0x0f,0xc0,0xff,0xff,0x03,0xfc,0xf0,0xff,0x3f,
 0xf0,0xff,0x0f,0x00,0xfc,0xf0,0xff,0x3f,0xf0,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };

const uint8_t pet_love[] PROGMEM = {
 0x00,0x00,0x0c,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x30,0x00,
 0x00,0x00,0x00,0x3f,0x38,0x0e,0xfc,0x00,0x00,0x00,0x00,0x3f,0x7c,0x1f,0xfc,
 0x00,0x00,0x00,0xc0,0x3f,0xfe,0x3b,0xff,0x03,0x00,0x00,0xc0,0x3f,0xfe,0x33,
 0xff,0x03,0x00,0x00,0xc0,0xff,0xf6,0x37,0xff,0x03,0x00,0x00,0xc0,0xff,0xe6,
 0x3f,0xff,0x03,0x00,0x00,0xf0,0xff,0xcc,0x1f,0xff,0x03,0x00,0x00,0xf0,0xff,
 0x98,0x0f,0xff,0x03,0x00,0x00,0xf0,0xff,0xb3,0xc7,0xff,0x0f,0x00,0x00,0xf0,
 0xff,0xe3,0xc3,0xff,0x0f,0x00,0x00,0xfc,0xff,0xc3,0xc1,0xff,0x0f,0x00,0x00,
 0xfc,0xff,0x83,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,
 0x00,0xfc,0xff,0x03,0xc0,0xff,0x0f,0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,
 0x00,0x00,0xfc,0xff,0x0f,0xf0,0xff,0x0f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,
 0xff,0x3f,0x00,0x00,0xff,0xff,0x0f,0xf0,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,
 0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,
 0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,
 0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,
 0x00,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,0x3f,0x00,0x00,0xff,0x03,0xfc,0xff,0xc0,
 0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,
 0x00,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,
 0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,
 0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,
 0xc0,0xf3,0x3f,0x0f,0x3f,0x00,0x00,0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,
 0xff,0x00,0xf0,0x3f,0x00,0x3f,0x00,0x00,0xff,0x07,0xfc,0x70,0xc0,0x3f,0x00,
 0x00,0xff,0x07,0xfc,0x70,0xc0,0x3f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x00,0xff,0xff,0x0f,0xc0,0xff,
 0x3f,0x00,0x00,0xff,0xff,0x0f,0xc0,0xff,0x3f,0x00,0x00,0xff,0xff,0x3f,0xf0,
 0xff,0xff,0x03,0x00,0xff,0xff,0x3f,0xf0,0xff,0xff,0x03,0xfc,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0x00,0xfc,0xf0,0xff,0xff,0xff,0xff,0x0f,0x00,0x00,0xfc,0xff,
 0xff,0xff,0xff,0x3f,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0x3f,0x00,0xe0,0x03,
 0xfc,0xff,0xff,0x3f,0xc0,0x03,0xe0,0x03,0xfc,0xff,0xff,0x3f,0xc0,0x03,0x18,
 0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x18,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,
 0x00,0x00,0xfc,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x00,0x00,
 0x00,0x00,0x00,0xfc,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0xfc,0xff,0xff,0x03,
 0x00,0x00 };


const uint8_t *pet_faces[] = {
  pet_normal, pet_happy, pet_sad, pet_boring,
  pet_sleep1, pet_sleep2, pet_sleep3, pet_love
};

#define PET_NORMAL   0
#define PET_HAPPY    1
#define PET_SAD      2
#define PET_BORING   3
#define PET_SLEEP1   4
#define PET_SLEEP2   5
#define PET_SLEEP3   6
#define PET_LOVE     7

int bar_values[4] = {180, 180, 180, 180};
const unsigned long interval = 1000;
unsigned long lastUpdateTime = 0;

const char* mainMenu[] = {"Besle", "Sev", "Oyna", "Uyu"};
const int mainMenuSize = sizeof(mainMenu) / sizeof(mainMenu[0]);

const char* feedMenu[] = {"Yemek", "Icecek", "Tatli"};
const int feedMenuSize = sizeof(feedMenu) / sizeof(feedMenu[0]);

const char* loveMenu[] = {"Saril", "Op", "Hediye"};
const int loveMenuSize = sizeof(loveMenu) / sizeof(loveMenu[0]);

const char* gameMenu[] = {"Yilan", "PingPong", "Tetris"};
const int gameMenuSize = sizeof(gameMenu) / sizeof(gameMenu[0]);

bool menuOpen = false;
bool inSubMenu = false;
int currentMenu = 0; // 0=ana,1=Besle,2=Sev,3=Oyna
int menuIndex = 0;
bool sleeping = false;
int sleepFrame = 0;
unsigned long lastSleepTime = 0;

bool loveAnimation = false;
unsigned long loveStartTime = 0;

const int buttonSelect = 3;
const int buttonUp = 2;
const int buttonDown = 4;

void drawBars() {
  int x = 13, y = 3, height = 6, spacing = 6;
  for (int i = 0; i < 4; i++) {
    int length = bar_values[i] / 4;
    u8g2.drawBox(x, y + i * (height + spacing), length, height);
  }
}

const uint8_t* selectFace() {
  if (loveAnimation) {
    if ((millis() - loveStartTime) / 500 % 2 == 0)
      return pet_faces[PET_LOVE];
    else
      return pet_faces[PET_HAPPY];
  }
  if (sleeping) return pet_faces[PET_SLEEP1 + (sleepFrame % 3)];
  if (bar_values[0] <= 90) return pet_faces[PET_SAD];
  if (bar_values[2] < 60) return pet_faces[PET_BORING];
  if (bar_values[2] < 120) return pet_faces[PET_NORMAL];
  return pet_faces[PET_HAPPY];
}

void drawMenu(const char* menu[], int size) {
  for (int i = 0; i < size; i++) {
    int x = 0;
    int y = 14 + i * 12 - 10;
    int w = 128;
    int h = 12;

    if (i == menuIndex) {
      u8g2.setDrawColor(1);
      u8g2.drawBox(x, y, w, h);
      u8g2.setDrawColor(0);
      u8g2.drawStr(5, 14 + i * 12, menu[i]);
      u8g2.setDrawColor(1);
    } else {
      u8g2.drawStr(5, 14 + i * 12, menu[i]);
    }
  }
}

void handleMenuInput() {
  int size = (inSubMenu ? 
    (currentMenu == 1 ? feedMenuSize : (currentMenu == 2 ? loveMenuSize : gameMenuSize)) : mainMenuSize);

  if (digitalRead(buttonUp) == LOW) {
    menuIndex = (menuIndex - 1 + size) % size;
    delay(200);
  }
  if (digitalRead(buttonDown) == LOW) {
    menuIndex = (menuIndex + 1) % size;
    delay(200);
  }
  if (digitalRead(buttonSelect) == LOW) {
    if (!inSubMenu) {
      if (menuIndex == 0) { inSubMenu = true; currentMenu = 1; menuIndex = 0; }
      else if (menuIndex == 1) { inSubMenu = true; currentMenu = 2; menuIndex = 0; }
      else if (menuIndex == 2) { inSubMenu = true; currentMenu = 3; menuIndex = 0; }
      else if (menuIndex == 3) { sleeping = true; menuOpen = false; }
    } else {
      if (currentMenu == 1) {
        if (menuIndex == 0) bar_values[1] = min(bar_values[1] + 16, 180); // Yemek
        else if (menuIndex == 1) bar_values[1] = min(bar_values[1] + 8, 180); // İçecek
        else if (menuIndex == 2) bar_values[1] = min(bar_values[1] + 20, 180); // Tatlı
      } else if (currentMenu == 2) {
        if (menuIndex == 0) bar_values[0] = min(bar_values[0] + 12, 180); // Sarıl
        else if (menuIndex == 1) bar_values[0] = min(bar_values[0] + 20, 180); // Öp
        else if (menuIndex == 2) bar_values[0] = min(bar_values[0] + 28, 180); // Hediye
        loveAnimation = true;
        loveStartTime = millis();
      } else if (currentMenu == 3) {
        bar_values[2] = min(bar_values[2] + 30, 180); // Mutluluk
      }

      inSubMenu = false;
      currentMenu = 0;
      menuIndex = 0;
      menuOpen = false;
    }
    delay(200);
  }
}

void setup() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tf);
  pinMode(buttonSelect, INPUT_PULLUP);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
  unsigned long currentTime = millis();

  // Barlar zamanla azalır
  if (!sleeping && !menuOpen && currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    for (int i = 0; i < 4; i++) if (bar_values[i] > 0) bar_values[i]--;
  }

  // Enerji artışı uykuda
  if (sleeping && currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    bar_values[3] = min(bar_values[3] + 2, 180);
  }

  // Uyuma animasyonu
  if (sleeping) {
    if (digitalRead(buttonSelect) == LOW) {
      sleeping = false;
      delay(200);
    } else if (currentTime - lastSleepTime >= 500) {
      lastSleepTime = currentTime;
      sleepFrame++;
    }
  }

  // Love animasyonu biterse kapat
  if (loveAnimation && millis() - loveStartTime >= 5000) {
    loveAnimation = false;
  }

  // Menü açma
  if (!menuOpen && !sleeping && digitalRead(buttonSelect) == LOW) {
    menuOpen = true;
    inSubMenu = false;
    currentMenu = 0;
    menuIndex = 0;
    delay(200);
  }

  if (menuOpen) {
    handleMenuInput();
  }

  // Ekran çizimi
  u8g2.firstPage();
  do {
    if (menuOpen) {
      if (!inSubMenu) drawMenu(mainMenu, mainMenuSize);
      else if (currentMenu == 1) drawMenu(feedMenu, feedMenuSize);
      else if (currentMenu == 2) drawMenu(loveMenu, loveMenuSize);
      else if (currentMenu == 3) drawMenu(gameMenu, gameMenuSize);
    } else {
      u8g2.drawXBMP(0, 0, 64, 64, bar_bitmap);
      drawBars();
      const uint8_t* face = selectFace();
      u8g2.drawXBMP(0, 64, 64, 64, face);
    }
  } while (u8g2.nextPage());

  delay(100);
}