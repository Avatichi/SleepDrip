#include "OLED_Driver.h"
#include "OLED_GUI.h"
#include "DEV_Config.h"
#include "Debug.h"

extern OLED_DIS sOLED_DIS;

void setup()
{
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  System_Init();

  OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;
  OLED_Init( OLED_ScanDir );

  OLED_ClearScreen(OLED_BACKGROUND);

}

void loop()
{

  GUI_DisString_EN(0, 0, "SLEEP", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
  GUI_DisString_EN(0, 20, "DRIP", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
  
  int i = 0;
  int j = 0;
  for (i = 0; i < 100; i++) {
    GUI_DisNum(0, 60, i, &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
    delay(1000);

    for (j = 0; j < 16; j ++) {
      OLED_ClearLine(0, 60 + j);
    }   
  }
}

