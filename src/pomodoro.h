#ifndef POMODORO_H
#define POMODORO_H

#include<stdint.h>
#include<stdbool.h>
#include<math.h>
#include "event_input.h"
#include "pomodoro_sessions.h"
#include "action.h"

#define setSesiones(...) setSessions(__VA_ARGS__)
/** \brief actualiza la cuenta y estado del pomodoro
 * \param objeto dirección de pomodoro*/
typedef enum {POMODORO_RUNNING, POMODORO_PAUSED, POMODORO_REACHED, 
	POMODORO_DISABLED}POMODORO_STATE;
POMODORO_STATE updatePomodoro(void);
void initPomodoro(void);
void destroyPomodoro(void);
#endif
