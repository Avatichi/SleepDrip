#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdint.h>

/* Hardware Configuration */
#define ATD							39
#define BATTERY_ADC					36

#define R_LED						13
#define Y_LED						14
#define G_LED						12

#define SPI_SLAVE_SELCET            10
#define SPI_DRIVER                  1


#define DATA_TYPE                   uint16_t
#define TIME_TYPE                   uint16_t
#define SLOPE_TYPE                  float

/* 
 * How many samples in a second to take
 * from 1 to 1000 samples per second
 */
#define SAMPLE_PER_SEC				1

/* On how many samples to calculate slope */
#define ARRAY_LEN                   700

/* syringe_size in cc */
#define SYRINGE_SIZE				50

#define SAMPLE_RESULATION           4096

/* 
 * How much error to get before indicate error to user
 * this number is the amount of time the state machine waits (in seconds)
 * until it indicated error, to stop false positives
 */
#define THRESHOLD_BAD_INJECTION		3

/* 
 * How much time in seconds takes to detect error
 * The bigger the number, the better the results will be, but it will take more time
 */
#define ERROR_DETCTION_TIME			20

#define DEBUG						1
// #define ONLY_SAMPLE					1

#endif /* __CONFIG_H__ */
