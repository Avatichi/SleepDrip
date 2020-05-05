#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdint.h>

#ifndef TEST
#include <HardwareSerial.h>
#endif

/* Hardware Configuration */
#define BATTERY_ADC					36
#define ATD							A0

#define R_LED						5
#define Y_LED						6
#define G_LED						7

#define BUTTON_ONE					2
#define BUTTON_TWO					3
#define BUTTON_THREE				4

#define SPI_SLAVE_SELCET			10

#define SPI_DRIVER					1
#define BAUDRATE_DEBUG				115200

#define DATA_TYPE					uint16_t
#define TIME_TYPE					uint32_t
#define SLOPE_TYPE					double

/*
 * How many samples in a second to take
 * from 1 to 1000 samples per second
 */
#define SAMPLE_PER_SEC				3 // 3
#define START_SAMPLE_SEC			60

/* On how many samples to calculate slope */
#define ARRAY_LEN					100

/* syringe_size in cc */
#define SYRINGE_SIZE				60

#define SAMPLE_RESULATION			65525

/*
 * How much error to get before indicate error to user
 * this number is the amount of time the state machine waits (in seconds)
 * until it indicated error, to stop false positives
 */
#define THRESHOLD_BAD_INJECTION		3

/*
 * How much time in seconds takes to detect error
 * The bigger the number, the better the results will be
 * but it will take more time
 */
#define ERROR_DETCTION_TIME			20


#define FIRST_INFO_LINE             85
#define SECOND_INFO_LINE            105
#define START_OFFSET                5

/* Testing */
#define FILE_PATH "../data/n5cc_1.txt"

#define DEBUG						1

#endif /* __CONFIG_H__ */
