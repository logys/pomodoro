#include "unity.h"
#include "handleLed.h"
#include "mock_timer.h"
#include "mock_led.h"
#include <stdbool.h>

void setUp(void)
{
	initTimer_Ignore();
	openLed_Ignore();
	initHandleLed();
	handleLedOn();
}

void tearDown(void)
{
}

void test_on_write_0_toggle_500ms(void)
{
	setAlarm_Expect(TIMER_LED, 500, MILLISECONDS);
	writeToLed(0);

	getAlarm_ExpectAndReturn(TIMER_LED, READY);
	setAlarm_Expect(TIMER_LED, 500, MILLISECONDS);
	toggleLed_Ignore();
	updateLed();

	getAlarm_ExpectAndReturn(TIMER_LED, READY);
	setAlarm_Expect(TIMER_LED, 500, MILLISECONDS);
	toggleLed_Ignore();
	updateLed();
}

void test_lock_while_toggling(void)
{
	setAlarm_Expect(TIMER_LED, 500, MILLISECONDS);
	writeToLed(0);

	getAlarm_ExpectAndReturn(TIMER_LED, UNREACHED);
	updateLed();

	writeToLed(0);
	writeToLed(100);
	writeToLed(5);
}

void test_off(void)
{
	handleLedOff();
	writeToLed(0);
	writeToLed(0);
	updateLed();
}

void test_8ms_toggle(void)
{
	setAlarm_Expect(TIMER_LED, 8, MILLISECONDS);
	writeToLed(100);

	getAlarm_ExpectAndReturn(TIMER_LED, READY);
	setAlarm_Expect(TIMER_LED, 8, MILLISECONDS);
	toggleLed_Ignore();
	updateLed();
}

void test_more_than_100_percernt(void)
{
	setAlarm_Expect(TIMER_LED, 8, MILLISECONDS);
	writeToLed(200);

	getAlarm_ExpectAndReturn(TIMER_LED, READY);
	setAlarm_Expect(TIMER_LED, 8, MILLISECONDS);
	toggleLed_Ignore();
	updateLed();
}


void test_less_than_0_percernt(void)
{
	setAlarm_Expect(TIMER_LED, 500, MILLISECONDS);
	writeToLed(-1);

	getAlarm_ExpectAndReturn(TIMER_LED, READY);
	setAlarm_Expect(TIMER_LED, 500, MILLISECONDS);
	toggleLed_Ignore();
	updateLed();
}
