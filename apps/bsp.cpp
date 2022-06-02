#include "bsp.hpp"
#include "avr/io.h"
#include <cstdint>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "signals.hpp"
#include <avr/sleep.h>

constexpr std::uint8_t BUZZER_PIN = PD4;
constexpr std::uint8_t BUTTON_PIN = PD2;
constexpr std::uint8_t LED_PIN = PD3;

using namespace BSP;
Bsp::Bsp() 
{
	//buzzer
	DDRD |= 1<<BUZZER_PIN;
	buzzer_off();
}

void Bsp::buzzer_off()
{
	PORTD &= ~(1<<BUZZER_PIN);
}

void Bsp::buzzing()
{
	for(int i = 0; i<6; i++){
		buzzer_toggle();
		_delay_ms(500);
	}
	buzzer_off();
}

void Bsp::buzzer_toggle()
{
	PIND |= 1<<BUZZER_PIN;
}

void Bsp::led_play()
{
	for(int i = 0; i<6; i++){
		led_toggle();
		_delay_ms(500);
	}
	led_off();
}

void Bsp::led_toggle()
{
	PIND |= 1<<LED_PIN;
}

void Bsp::led_off()
{
	PORTD &= ~(1<<LED_PIN);
}

void Bsp::standBy()
{
	sei();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();
}

void Bsp::idle()
{
	DDRB |= 1<<PB5;
	PORTB &=~(1<<PB5);
	sei();
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_mode();
	PORTB |= 1<<PB5;
}

namespace BSP 
{
Controller * controller_ = nullptr;
TickOneSecond * tick_ = nullptr;

void timer2Config();
void pcintConfig();

void bsp_input(TickOneSecond * tick, Controller * controller)
{
	controller_ = controller;
	tick_ = tick;
	timer2Config();
	pcintConfig();
	sei();

	DDRD |= 1<<PD3;
}

void timer2Config()
{
	//CTC mode timer2
	TCCR2A |= 1<<WGM21 | 0<<WGM20;
	//1024 preescaler
	TCCR2B |= 1<<CS22 | 1<<CS21 | 1<<CS20;
	TIMSK2 |= 1<<OCIE2A;;
	TCNT2 = 0;
	//10ms
	OCR2A = 155;
}

void pcintConfig()
{
	DDRD &= ~(1<<BUTTON_PIN);
	PORTD |= 1<<BUTTON_PIN;
	EICRA |= 1<<ISC01;
	EICRA &= ~(1<<ISC00);
	EIMSK |= 1<<INT0;
}

ISR(INT0_vect)
{
	controller_->addSignal(Signals::PRESSED);
}

ISR(TIMER2_COMPA_vect)
{
	tick_->callTick();
}

void led_toggle()
{
	PIND |= 1<<PD3;
}
}
