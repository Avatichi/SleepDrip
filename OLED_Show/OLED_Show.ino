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

  Serial.println("OLED Init ");
  OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;
  OLED_Init( OLED_ScanDir );

  Serial.println("OLED_Show ");
  //GUI_Show();
  OLED_ClearBuf();
  OLED_ClearScreen(OLED_BACKGROUND);

}

void loop()
{
  uint8_t sec = 0;
  // DEV_TIME sDev_time;
  // sDev_time.Hour = 12;
  // sDev_time.Min = 34;
  // sDev_time.Sec = 56;
  // Serial.print("Show time\r\n");
  // for (;;) {
  //   sec++;
  //   sDev_time.Sec = sec;
  //   if (sec == 60) {
  //     sDev_time.Min = sDev_time.Min + 1;
  //     sec = 0;
  //     if (sDev_time.Min == 60) {
  //       sDev_time.Hour =  sDev_time.Hour + 1;
  //       sDev_time.Min = 0;
  //       if (sDev_time.Hour == 24) {
  //         sDev_time.Hour = 0;
  //         sDev_time.Min = 0;
  //         sDev_time.Sec = 0;
  //       }
  //     }
  //   }
  GUI_DisString_EN(33, 2, "HELLO!", &SUPPORT_FONT, FONT_BACKGROUND, WHITE);
  OLED_DisPage(0, 1);
  OLED_ClearBuf();
    // GUI_Showtime(28, 0, 100, 16, &sDev_time, WHITE);
    // OLED_Display(0, 72, 128, 72 + 16);
    // Driver_Delay_ms(1000);//Analog clock 1s
  // }
}

