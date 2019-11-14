#include"entrada.h"
#ifdef TEST
	#include"stub_io.h"
#elif ATTINY
	#include<avr/io.h>
#elif STM32
	#include<libopencm3/stm32/rcc.h>
	#include<libopencm3/stm32/gpio.h>
#endif

struct button{
	short state;
	short last_state;
	bool timer_seted;
}button;

TIMER button_timer;
#ifdef ATTINY
//Drivers Attiny
void openPush(void)
{
        /*Inicia el driver push Buttons*/
        DDRB &= ~(1<<PB3);
        PORTB |= (1<<PB3);
	button_timer = newTimer();
	button.state = OFF;
	button.last_state = OFF;
	button.timer_seted = false;
}
void closePush(void)
{
        /*Inicia el driver push Buttons*/
        DDRB &= ~((1<<PB3));
        PORTB &= ~((1<<PB3));
	free(button_timer);
}
/*Push buttons*/
PUSH_STATE readPush(void)
{
        if(PINB&(1<<PB3)){
		button.state = OFF;
	}else{
		button.state = ON;
	}
	if(button.state != button.last_state && !button.timer_seted){
		setTimer(button_timer, 50, MILLISECONDS);
		button.timer_seted = true;
	}else if(button.timer_seted){
		getTimer(button_timer, MILLISECONDS) < 50 ? 
			button.state = button.last_state :
			(button.timer_seted = false);
	}

	button.last_state = button.state;
        return button.state;

}
#else
//Drivers Stm32f0
void openPush(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA,
			GPIO_MODE_INPUT,
			GPIO_PUPD_PULLUP,
			GPIO0);
}
void closePush(void)
{
	gpio_mode_setup(GPIOA,
			GPIO_MODE_INPUT,
			GPIO_PUPD_NONE,
			GPIO0);
}
uint8_t readPush(void)
{
	if(gpio_get(GPIOA, GPIO0))
		return 1;
	return 0;
}
#endif
