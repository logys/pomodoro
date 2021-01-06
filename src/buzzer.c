#ifdef TEST
	#include "stub_io.h"
#endif
#include"buzzer.h"
#include"timer.h"
#include<avr/io.h>
void buzzer_create(Buzzer * buzzer, short pin)
{
	buzzer->pin = pin;
	DDRB |= 1 << pin;
	PORTB &=~ (1 << pin);
}
void buzzer_a(int8_t ticks, int32_t  tiempoms)
{
	if(ticks <= 0 || tiempoms <= 0)
		return;
	if(ticks > 10)
		ticks = 10;
	if(tiempoms > 1000)
		tiempoms = 1000;
	for(uint8_t i = 0; i < ticks*2; i++){
	//	delay(tiempoms);
		toggle();
	}
}

//Drivers ATTINY
void buzzer_open(void)
{
	/* Inicia el driver buzzer*/
	DDRB |= (1<<PB1);
	PORTB &= ~(1<<PB1);
}
void buzzer_close(void)
{
        /*Inicia el driver buzzer*/
        DDRB &= ~(1<<PB1);
        PORTB &= ~(1<<PB1);
}
/*Buzzer encendido y apagado*/
void buzzer_write(BUZZER_STATE estado)
{
        if(estado == BUZZER_ON)
                PORTB |= (1<<PB1);
        else if(estado == BUZZER_OFF)
                PORTB &= ~(1<<PB1);
}
unsigned short readBuzz(void)
{
        /*Regresa el estado del buzzer*/
        return PINB&(1<<PB1)?BUZZER_ON:BUZZER_OFF;
}

void toggle(void)
{
	PINB |= 1<<PB1;
}
