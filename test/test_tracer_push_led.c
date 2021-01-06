#include "/home/antonio/.gem/ruby/gems/ceedling-0.30.0/vendor/unity/src/unity.h"
//#include "unity.h"
#include "../src/pomodoro.h"
#include "../src/pomodoro_sessions.h"
#include "spy_time.h"
#include "spy_led.h"
#include "spy_poweroff.h"
#include <stdlib.h>
#include "../src/led.h"
#include "../src/button.h"
#include "../src/buzzer.h"
#include "avr/io.h"
#include "../src/draw.h"
#include "../src/input.h"

#define LED_PIN 1
#define BUZZER_PIN 2
#define BUTTON_PIN 3
Led led;
Button button;
Buzzer buzz;
void setUp(void)
{
	DDRB = 0;
	PORTB = 0xFF;
	led_create(&led, LED_PIN);
	button_create(&button, BUTTON_PIN);
	buzzer_create(&buzz, BUZZER_PIN);
	pomodoro_init();
	draw_init(&led, &buzz);
}
void tearDown(void)
{
}
void test_pomodoro_at_init_led_on(void)
{
	input_update();
	pomodoro_update();
	draw_update();
	TEST_ASSERT_BITS(1<<LED_PIN, 1<<LED_PIN, DDRB);
	TEST_ASSERT_BITS(1<<LED_PIN, 1<<LED_PIN, PORTB);
	TEST_ASSERT_BITS(1<<BUTTON_PIN, 0, DDRB);
	TEST_ASSERT_BITS(1<<BUTTON_PIN, 0, PORTB);
	TEST_ASSERT_BITS(1<<BUZZER_PIN, 1<<BUZZER_PIN, DDRB);
	TEST_ASSERT_BITS(1<<BUZZER_PIN, 0, PORTB);
}
