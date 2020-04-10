#ifndef __SCREEN_UTILS_H__
#define __SCREEN_UTILS_H__

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "error_values.h"


extern int BATTERY_ADC;

void setup_screen();
void screen_loop(int inzector_value, status_t status);

#endif /* __SCREEN_UTILS_H__ */
