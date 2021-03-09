/*Controla el funcionamiento de un buzzer, 
 * pita un número indicado de veces, por le tiempo indicado,
 * enciende y apaga el pitido
 * */
#ifndef BUZZER_H
#define BUZZER_H
#include<stdint.h>
#include"timer.h"

typedef struct Buzzer{
	short pin;
}Buzzer;
void buzzer_create(Buzzer *, short pin);
typedef enum{BUZZER_OFF, BUZZER_ON} BUZZER_STATE;
/** \file buzzer.h 
 * \brief controla el buzzer
 * \param ticks Número de pitidos
 * \param tiempoms tiempo de duración de pitidos y silencio*/
void buzzer_a(int8_t  ticks, int32_t  tiempoms);
/* * \brief Inicia el buzzer*/
void buzzer_open(void);
/* * Detiene buzzer*/
void buzzer_close(void);
/** \brief Enciende y apaga el buzzer
 * \param estado ON, OFF*/
void buzzer_write(BUZZER_STATE);
/** \brief obtiene el estado del buzzer
 * \return unsigned short*/
void toggle(void);

void buzzer_init(const short pin);
#endif
