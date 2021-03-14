//#ifdef TEST

#include "unity.h"

#include "../src/blinker.h"
#include "fff.h"


DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(led_on);
FAKE_VOID_FUNC(led_toggle);
FAKE_VALUE_FUNC(double, timer_getTime);
FAKE_VOID_FUNC(timer_create);
FAKE_VOID_FUNC(timer_reset);

short progress;

void setUp(void)
{
	progress = 0;
	blinker_init(1, &progress);
	RESET_FAKE(led_toggle);
}

void tearDown(void)
{
}

void test_progress_cero_blink_500ms(void)
{
	progress = 0;
	int number_of_toggles = 10;
	timer_getTime_fake.return_val = 500;

	for(int i = 0; i < number_of_toggles; i++){
		blinker_do();
	}

	TEST_ASSERT_EQUAL(number_of_toggles, led_toggle_fake.call_count);
}

void test_progress_oneHundred_blink_16ms(void)
{
	progress = 100;
	int number_of_toggles = 10;
	timer_getTime_fake.return_val = 16;

	for(int i = 0; i < number_of_toggles; i++){
		blinker_do();
	}

	TEST_ASSERT_EQUAL(number_of_toggles, led_toggle_fake.call_count);
}

void test_no_toggle_when_no_reached(void)
{
	progress = 0;
	int number_of_toggles = 5;
	timer_getTime_fake.return_val = 16;

	for(int i = 0; i < number_of_toggles; i++){
		blinker_do();
	}

	TEST_ASSERT_EQUAL(0, led_toggle_fake.call_count);
}
//#endif // TEST
