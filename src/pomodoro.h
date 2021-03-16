#ifndef POMODORO_H
#define POMODORO_H

/*
 * Dispositivo que mide el tiempo indicado, registra y reproduce las sesiones indicadas,
 * indica el final de las sesiones con un pitido determinado, indica el progreso de las 
 * sesiones con un parpadeo de un led, lento cuando inicia y rápido cuando termina, el progreso
 * puede ser interrumpido para pausarse o apagarse presionando el botón , una vez apagado 
 * puede reiniciarse pulsando el botón nuevamente.
 * Cada vez que se inicia desde el apagado el pomodoro se reinicia.
 */

void pomodoro_init(short, short, short, int);
void pomodoro_update(void);
void pomodoro_reinit(void);

#endif
