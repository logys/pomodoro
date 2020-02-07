#include "unity.h"
#include "pomodoro.h"
#include "mock_event_input.h"
#include "pomodoro_sessions.h"
#include "mock_action.h"

RUN_STATE foo(void)
{

}

void setUp(void)
{
	initEventInput_Expect();
	initPomodoro();
	action = foo;
}

void tearDown(void)
{
	destroyEventInput_Expect();
	destroyPomodoro();
}

static void assertActionPowerOff(void)
{
	setActionPowerOff_Expect();
}
static void setInputEvent(short event)
{
	readEvent_ExpectAndReturn(event);
}
void test_init_pomodoro(void)
{
	initEventInput_Expect();
	initPomodoro();

	setInputEvent(NONE);
	assertActionPowerOff();
	TEST_ASSERT_EQUAL(POMODORO_REACHED, updatePomodoro());
}
void test_init_and_call_poweroff(void)
{
	setInputEvent(NONE);
	assertActionPowerOff();
	TEST_ASSERT_EQUAL(POMODORO_REACHED, updatePomodoro());
}
void test_destroy_pomodoro(void)
{
	destroyEventInput_Expect();
	destroyPomodoro();
}
static void assertFirstCallPowerOff(void)
{
	setInputEvent(NONE);
	assertActionPowerOff();
	updatePomodoro();
}
void test_button_return_none_pomodoro_call_no_change(void)
{
	assertFirstCallPowerOff();
	setInputEvent(NONE);
	TEST_ASSERT_EQUAL(POMODORO_RUNNING, updatePomodoro());
}
static void assertToggle(void)
{
	setActionTogglePlayPause_Expect();
}
void test_button_return_play_pause_toggle_play_pause(void)
{
	assertFirstCallPowerOff();

	setInputEvent(PLAY_PAUSE);
	assertToggle();
	TEST_ASSERT_EQUAL(POMODORO_RUNNING, updatePomodoro());

	setInputEvent(PLAY_PAUSE);
	assertToggle();
	TEST_ASSERT_EQUAL(POMODORO_RUNNING, updatePomodoro());
}

void test_button_return_none_call_no_change_after_play_pause(void)
{
	assertFirstCallPowerOff();

	setInputEvent(PLAY_PAUSE);
	assertToggle();
	TEST_ASSERT_EQUAL(POMODORO_RUNNING, updatePomodoro());

	setInputEvent(NONE);
	TEST_ASSERT_EQUAL(POMODORO_RUNNING, updatePomodoro());
}

void test_button_return_power_off_setActionPowerOff(void)
{
	assertFirstCallPowerOff();

	setInputEvent(POWEROFF);
	assertActionPowerOff();
	TEST_ASSERT_EQUAL(POMODORO_REACHED, updatePomodoro());
}
