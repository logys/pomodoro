#include "unity.h"
#include "handleLed.h"
#include "mock_timer.h"
#include "mock_led.h"
#include <stdbool.h>

void setUp(void)
{
	initTimer_Ignore();
	openLed_Ignore();
	newTimer_ExpectAndReturn(NULL);
	initHandleLed();
}

void tearDown(void)
{
}

void test_set_sesion(void)
{
	setTimer_Expect(NULL, 500, MILLISECONDS);
	writeToLed(0);
}

void test_on_cero_toggle_after_500ms(void)
{
	setTimer_Expect(NULL, 500, MILLISECONDS);
	writeToLed(0);

	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 500);
	toggleLed_Expect();
	updateLed();
}
