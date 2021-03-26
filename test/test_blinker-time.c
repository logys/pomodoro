//#ifdef TEST

#include "unity.h"

#include "../src/blinker.h"
#include "../src/timer.h"
#include "../src/millis.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "fff.h"
#include <stdint.h>


DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(led_on);
FAKE_VOID_FUNC(led_off);
FAKE_VOID_FUNC(led_toggle);

short progress;

void setUp(void)
{
	RESET_FAKE(led_toggle);

	progress = 0;
	blinker_init(&progress);
}

void tearDown(void)
{
}

void test_progress_cero_blink_500ms(void)
{
	progress = 0;

	for(int i = 0; i < 1000; i++){
		TIM1_COMPA_vect();
		blinker_do();
	}

	TEST_ASSERT_EQUAL(2, led_toggle_fake.call_count);
}
void test_progress_oneHundred_blink_16ms(void)
{
	progress = 99;
	int number_of_ticks = 1000;

	for(int i = 0; i < number_of_ticks; i++){
		TIM1_COMPA_vect();
		blinker_do();
	}
	// 1000 / 16  = 62 
	TEST_ASSERT_EQUAL(83, led_toggle_fake.call_count);
}

void test_no_toggle_when_no_reached(void)
{
	progress = 0;

	for(int i = 0; i < 400; i++){
		TIM1_COMPA_vect();
		blinker_do();
	}

	TEST_ASSERT_EQUAL(0, led_toggle_fake.call_count);
}
//#endif // TEST
