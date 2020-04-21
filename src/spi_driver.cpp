#include "../include/spi_driver.h"


void spi_setup()
{
    pinMode (SPI_SLAVE_SELCET, OUTPUT);
    SPI.begin();
}


void spi_read(int *value)
{
    digitalWrite(SPI_SLAVE_SELCET, LOW);
    // TODO: Check This, 
    delayMicroseconds(10);

    byte adcByteHigh = SPI.transfer(0x00);
    byte adcByteMid = SPI.transfer(0x00);
    byte adcByteLow = SPI.transfer(0x00);

    // adcByteHigh &= 0b00000011;  // Tried excluding some bits but not sure which ones
    digitalWrite(SPI_SLAVE_SELCET, HIGH); 
    // long ADCresult = ((adcByteHigh << 16) | (adcByteMid << 8) | adcByteLow );
    *value = ((adcByteHigh << 14) | (adcByteMid << 6) | (adcByteLow >> 2));
}
