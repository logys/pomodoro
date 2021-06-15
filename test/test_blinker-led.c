//#ifdef TEST

#include "unity.h"

#include "../src/blinker.h"
#include "../src/led.h"
#include <avr/io.h>
#include "fff.h"
#include <stdint.h>
#include "../src/gpioHandler.h"


DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint32_t, timer_getTime);
FAKE_VOID_FUNC(timer_create);
FAKE_VOID_FUNC(timer_restart);

short progress;
bool finished;
short led_pin;

void setUp(void)
{
	progress = 0;
	finished = false;
	blinker_init(&progress, &finished);
	led_pin = 5;
	led_open(led_pin);
}

void tearDown(void)
{
}

void test_progress_blink_500ms(void)
{
	progress = 0;
	timer_getTime_fake.return_val = 500;
	short pin = gpio_pinToGpio(led_pin);

	blinker_do();

	TEST_ASSERT_BITS(1<<pin, 1<<pin, PORTB);
}

void test_no_blink(void)
{
	progress = 0;
	timer_getTime_fake.return_val = 100;
	short pin = gpio_pinToGpio(led_pin);

	blinker_do();

	TEST_ASSERT_BITS(1<<pin, 0<<pin, PORTB);
}

void test_progress_oneHundred_blink_16ms(void)
{
	progress = 99;
	int number_of_toggles = 99;
	short pin = gpio_pinToGpio(led_pin);
	timer_getTime_fake.return_val = 16;

	for(int i = 0; i < number_of_toggles; i++){
		blinker_do();
	}

	TEST_ASSERT_BITS(1<<pin, 1<<pin, PORTB);
}

//#endif // TEST
