/*
 * button.h
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#ifndef INC_THREADS_BUTTON_H_
#define INC_THREADS_BUTTON_H_

#include <stdbool.h>

void ButtonHandleTask(void *argument);
void ButtonExecuteTask(void *argument);

void CreateButtonThread(void);
void interferenceCheck(void);
void set_timer6Alarm(bool timer6Alarm_in);
void set_timer7Alarm(bool timer7Alarm_in);
void set_extiAlarmPA0(bool extiAlarmPA0_in);

#endif /* INC_THREADS_BUTTON_H_ */
