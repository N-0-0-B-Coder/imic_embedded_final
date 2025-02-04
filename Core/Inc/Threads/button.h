/*
 * button.h
 *
 *  Created on: Feb 4, 2025
 *      Author: daoch
 */

#ifndef INC_THREADS_BUTTON_H_
#define INC_THREADS_BUTTON_H_

void ButtonHandleTask(void *argument);
void ButtonExecuteTask(void *argument);

void CreateButtonThread(void);

#endif /* INC_THREADS_BUTTON_H_ */
