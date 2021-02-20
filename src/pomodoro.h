#ifndef POMODORO_H
#define POMODORO_H

#include "pomodoro_sessions.h"
#include <stdint.h>
#include "session.h"
#include "time.h"

/*
 * Dispositivo que mide el tiempo indicado, registra y reproduce las sesiones indicadas,
 * indica el final de las sesiones con un pitido determinado, indica el progreso de las 
 * sesiones con un parpadeo de un led, lento cuando inicia y rápido cuando termina, el progreso
 * puede ser interrumpido para pausarse o apagarse presionando el botón , una vez apagado 
 * puede reiniciarse pulsando el botón nuevamente.
 * Cada vez que se inicia desde el apagado el pomodoro se reinicia.
 */
typedef enum pin_type {PIN_BUZZER=0, PIN_LED, PIN_BUTTON}PIN_TYPE;
typedef struct Pomodoro{
	int input;
	int progress;
	Session play;
}Pomodoro;

void pomodoro_init(Pomodoro *);
void pomodoro_destroy(void);
#define pomodoro_setSessions(...) sessions_set(__VA_ARGS__)
/** \brief actualiza la cuenta y estado del pomodoro
 * \param objeto dirección de pomodoro*/
void pomodoro_update(void);
void pomodoro_draw(void);
bool pomodoro_setPin(PIN_TYPE, short pin);
#endif
