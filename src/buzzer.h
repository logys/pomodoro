#ifndef BUZZER_H
#define BUZZER_H
#include<stdint.h>
#include"timer.h"
#define ON 1
#define OFF 0
/** \file buzzer.h 
 * \brief controla el buzzer
 * \param ticks Número de pitidos
 * \param tiempoms tiempo de duración de pitidos y silencio*/
void buzzer(int8_t  ticks, int32_t  tiempoms);
/* * \brief Inicia el buzzer*/
void openBuzzer(void);
/* * Detiene buzzer*/
void closeBuzzer(void);
/** \brief Enciende y apaga el buzzer
 * \param estado ON, OFF*/
void writeBuzz(short const estado);
/** \brief obtiene el estado del buzzer
 * \return unsigned short*/
unsigned short readBuzz(void);
void toggle(void);
#endif
