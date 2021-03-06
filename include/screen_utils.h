#ifndef __SCREEN_UTILS_H__
#define __SCREEN_UTILS_H__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#ifdef ESP
    #include <Wire.h>
#endif

#include "error_values.h"
#include "config.h"

void setup_screen(void);
void screen_loop(int inzector_value, status_t status);

#endif /* __SCREEN_UTILS_H__ */
