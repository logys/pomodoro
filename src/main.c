/**
 * \file 
 * \brief main de este proyecto
 * \mainpage Description
 * Programa simple que implementa un pomodoro para sesiones de estudio. El
 * dispositivo cuenta con un buzzer que indica el termino e inicio de una 
 * sesión, un led que muestra el progreso del tiempo de sesión y un par de 
 * botones para controlarlo.
 *
 * \author Logy
 * \version 2.0 
 * \bug no por ahora
 * \warning sin pruebas
 * */
//Para AVR
#ifdef ATTINY
#include<avr/interrupt.h>
#include<avr/sleep.h>
#endif
#include<stdint.h>
#include<stdlib.h>
#include"log.h"
#include"entrada.h"
#include"pomodoro.h"
#include"delay.h"
#include"led.h"

#define APAGADO 2
#define TOGGLE 1
#define NADA 0
void apagar(void);
int main(void)
{
	openPush();
	openLed();
	struct pomodoro pomodor;
	setSesiones(&pomodor, 20, 5, 20, 5, 20);
	//setSesiones(&pomodor, 1, 1, 1, 1, 1);
	uint8_t boton, estado = 4;
	while(1){
		boton = botonEvent();
		if(boton == TOGGLE)
			estado == NADA? estado = TOGGLE: (estado = NADA);
		else if(boton == APAGADO)
			estado = APAGADO;
		
		switch(estado)
		{
			case NADA:
				if(actualizar(&pomodor))
					estado = APAGADO;
				break;
			case TOGGLE:
				toggleLed();
				pausa(&pomodor);
				break;
			case APAGADO:
				apagar();
				estado = TOGGLE;
				reiniciarMillis();
				reiniciar(&pomodor);
				break;
		}
	}
}

#ifdef ATTINY
void apagar(void)
{
	GIMSK |= (1<<PCIE);
	PCMSK |= (1<<PB3);
	writeLed(0);
	delay(2000);
	MCUCR |= (1<<SM1)|(0<<SM0);
	sleep_mode();
}

ISR(PCINT0_vect)
{
}
#else
void apagar(void)
{

}
#endif
