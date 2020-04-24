#ifdef ATTINY
#include<avr/io.h>
#else
#include<libopencm3/stm32/rcc.h>
#include<libopencm3/stm32/gpio.h>
#endif
#include"log.h"
#include"timer.h"
#include<stdint.h>

#define REPETICIONES 5
#define TIMPOERROR 100
#define TIMPODEBUG 200

static int8_t logon = 0;	//Global variable
static void setLed(unsigned short const parpadeos, unsigned short delayms);

void logLed(short const sistema, short const nivel, char const *mensaje)
{
	/*Enciende el Led en una secuencia determinada, dependiente del
	 *tipo de error*/
	if(logon == 0){
		setLed(100, TIMPOERROR);
	}else{
		if(sistema == BUZZ){
			for(int16_t i = 0; i < REPETICIONES; i++){
				if(nivel == ERROR){
					setLed(10, TIMPOERROR);
				}else if(nivel == DEBUG){
					setLed(5, TIMPODEBUG);
				}
			}
		}else if(sistema == PUSH){
			setLed(2, TIMPOERROR);
		}
	}
	closeLog();
}

void logGlobalOn(void)
{
	logon = 1;
}

void logGlobalOff(void)
{
	logon = 0;
}

static void setLed(unsigned short const parpadeos, unsigned short delayms)
{
	uint32_t tiempo = millis();
	for(int i = 0; i < parpadeos; i++){
		if(readLog())	//Si está encendido apaga
			writeLog(OFF);
		else
			writeLog(ON);
		while(delayms > (millis()- tiempo))
			__asm__ __volatile__ ("nop");
	}
}
//Drivers ATTINY
#ifdef ATTINY
void openLog(void)
{
        /*Inicia el driver loggin*/
        DDRB |= (1<<PB2);
        PORTB &= ~(1<<PB2);
}
void closeLog(void)
{
        /*Inicia el driver loggin*/
        DDRB &= ~(1<<PB2);
        PORTB &= ~(1<<PB2);
}

/*Led log*/
void writeLog(short const estado)
{
        if(estado == ON)
                PORTB |= (1<<PB2);
        else if(estado == OFF)
                PORTB &= ~(1<<PB2);
}
short int readLog(void)
{
        return PINB&(1<<PB2);
}
#else
//Drivers stm32
void openLog(void)
{
        /*Inicia el driver loggin*/
        rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA,
			GPIO_MODE_OUTPUT,
			GPIO_PUPD_NONE,
			GPIO2);
}
void closeLog(void)
{
        /*Inicia el driver loggin*/
	gpio_mode_setup(GPIOA,
			GPIO_MODE_INPUT,
			GPIO_PUPD_NONE,
			GPIO2);
}
void writeLog(short const estado)
{
        if(estado == ON)
		gpio_set(GPIOA, GPIO2);
        else if(estado == OFF)
		gpio_clear(GPIOA, GPIO2);
}
short int readLog(void)
{
        return gpio_get(GPIOA, GPIO2);
}
#endif
