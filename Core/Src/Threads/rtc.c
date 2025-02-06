/*
 * rtc.c
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#include <stdio.h>
#include <stdbool.h>
#include <cmsis_os2.h>
#include "rtc.h"
#include "uart.h"

void CreateRTCTimeThread(void) {
  // rtcTimeExecute Thread
  osThreadId_t rtcTimeExecute;
  const osThreadAttr_t rtcTimeExecute_attributes ={
	.name = "rtcTimeExecute",
	.stack_size = 512 * 4,
	.priority = (osPriority_t) osPriorityNormal1,
  };

  rtcTimeExecute = osThreadNew(startRTCTime, NULL, &rtcTimeExecute_attributes);
  if (NULL == rtcTimeExecute) PRINT_UART("rtcTimeSet Thread is failed to be created\r\n");
  else PRINT_UART("rtcTimeSet Thread created successfully\r\n");
}

void startRTCTime(void *argument) {
	PRINT_UART("RTC Time Thread run\r\n");
	osDelay(1);
	//char weekDay[8][9] = { "", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	char pm[2][2] = {"AM", "PM"};

//	// Set up the RTC DS3231 for the first time
//	i2cWrite(DS3231_ADDRESS, DS3231_SECONDS, 0x12); 		// Seconds as 12 seconds
//	i2cWrite(DS3231_ADDRESS, DS3231_MINUTES, 0x12); 		// Minutes as 12 minutes
//	i2cWrite(DS3231_ADDRESS, DS3231_HOURS, 0x72); 			// Hours as 12 hours, 12h format, PM
//	i2cWrite(DS3231_ADDRESS, DS3231_DAY, 0x01);				// Week day as 1 (Sunday)
//	i2cWrite(DS3231_ADDRESS, DS3231_DATE, 0x05);			// Date of month (5)
//	i2cWrite(DS3231_ADDRESS, DS3231_CEN_MONTH, 0x01);		// Month (1 as January), Century (Bit 7 as 0 for 2000 - 2099)
//	i2cWrite(DS3231_ADDRESS, DS3231_2LDIGI_YEAR, 0x25);		// Year (25 as 2 last digit)

	// Infinite loop to read the data every 3s
	for (;;) {
		PRINT_UART("print DTS value\r\n");
		uint8_t seconds, minutes, hours, day, date, month, year, isPM;
		readDS3231Time(&seconds, &minutes, &hours, &day, &date, &month, &year, &isPM);
		PRINT_UART("Time: %02d:%02d:%02d %s\r\n", hours, minutes, seconds, pm[isPM]);
		PRINT_UART("Date: %02d/%02d/20%02d, Day: %d\r\n", date, month, year, day); //weekDay[day]
		//PRINT_UART("Time: %02d:%02d:%02d %s\r\n", 12, 12, 12, "PM");
		//PRINT_UART("Date: %02d/%02d/20%02d, Day: %s\r\n", 12, 12, 2012, "Tue");
		osDelay(3000);
	}
}
