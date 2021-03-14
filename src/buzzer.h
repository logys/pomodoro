/*Controla el funcionamiento de un buzzer, 
 * pita un número indicado de veces, por le tiempo indicado,
 * enciende y apaga el pitido
 * */
#ifndef BUZZER_H
#define BUZZER_H
#include<stdint.h>

void buzzer_on(void);
void buzzer_off(void);
void buzzer_open(short const pin);

#endif
