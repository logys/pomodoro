#ifndef POMODORO_H
#define POMODORO_H

#include<stdint.h>
#include<stdbool.h>
#include<math.h>
#include "timer.h"
#include "event_input.h"
#include "buzzer.h"
#include "handleLed.h"
#include "apagar.h"
#include "pomodoro_sessions.h"

#define setSesiones(...) setSessions(__VA_ARGS__)
/** \brief actualiza la cuenta y estado del pomodoro
 * \param objeto dirección de pomodoro*/
typedef enum {INPROGRESS, REACHED, DISABLED}POMODORO_STATE;
POMODORO_STATE updatePomodoro(void);
/** \brief Pausa sesiones 
 * \param objeto dirección de pomodoro*/
void pausa(void);
void initPomodoro(void);
void destroyPomodoro(void);
void enablePomodoro(void);
void disablePomodoro(void);
#endif
