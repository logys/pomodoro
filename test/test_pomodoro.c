#include "unity.h"
#include "pomodoro.h"
#include "mock_timer.h"
#include "mock_event_input.h"
#include "mock_handleLed.h"
#include "mock_buzzer.h"
#include "mock_apagar.h"
#include "pomodoro_sessions.h"

void setUp(void)
{
	initTimer_Expect();
	initEventInput_Expect();
	initHandleLed_Expect();
	openBuzzer_Expect();
	newTimer_ExpectAndReturn(NULL);
	initPomodoro();
	enableTimer_Expect(NULL);
	enablePomodoro();
}

void tearDown(void)
{
}

void setTimerTime(double time, UNIT_TIME unit_time);
void assertBuzzerOddSession(void);
void assertBuzzerEvenSession(void);
void test_pomodoro_enable_return_normal_output(void)
{
	setTimerTime(-1, MINUTES);
	TEST_ASSERT_EQUAL(INPROGRESS, updatePomodoro());
}
void test_pomodoro_disable_return_DISABLED(void)
{
	disablePomodoro();
	TEST_ASSERT_EQUAL(DISABLED, updatePomodoro());
}

void test_session_one_minute_unreached(void)
{
	int minutes_for_session = 1;
	setSesiones(minutes_for_session);
	
	int actual_minute_time = 0.5;
	setTimerTime(actual_minute_time, MINUTES);
	TEST_ASSERT_EQUAL(INPROGRESS, updatePomodoro());
}

void setTimerTime(double time, UNIT_TIME unit_time)
{
	getTimer_ExpectAndReturn(NULL, MINUTES, time);
}

void test_session_one_minute_reached(void)
{
	int minutes_for_session = 1;
	setSesiones(minutes_for_session);

	int actual_minute_time = 1;
	setTimerTime(actual_minute_time, MINUTES);
	assertBuzzerOddSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());
}
void assertBuzzerOddSession(void)
{
	buzzer_Expect(2, 400);
}

void test_two_buzzer_on_reached_session(void)
{
	int minutes_for_session = 1;
	setSesiones(minutes_for_session);

	int actual_minute_time = minutes_for_session;
	setTimerTime(actual_minute_time, MINUTES);
	assertBuzzerOddSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());
}

void test_two_sessions_unreached_second_session(void)
{
	int minutes_for_session_one = 2,
	    minutes_for_session_two = 3;
	setSesiones(minutes_for_session_one, minutes_for_session_two);

	setTimerTime(minutes_for_session_one, MINUTES);
	assertBuzzerOddSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());

	setTimerTime(minutes_for_session_two -1, MINUTES);
	TEST_ASSERT_EQUAL(INPROGRESS, updatePomodoro());
}

void test_two_sessions_reached_second_session(void)
{
	int minutes_for_session_one = 2,
	    minutes_for_session_two = 3;
	setSesiones(minutes_for_session_one, minutes_for_session_two);

	setTimerTime(minutes_for_session_one, MINUTES);
	assertBuzzerOddSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());

	setTimerTime(minutes_for_session_two, MINUTES);
	assertBuzzerEvenSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());
}
void assertBuzzerEvenSession(void)
{
	buzzer_Expect(4, 100);
}

void assertBuzzerNanSession(void)
{
	buzzer_Expect(1, 1000);
}
void test_buzzer_long_after_last_session(void)
{
	int minutes_for_session = 10;
	setSesiones(minutes_for_session);

	setTimerTime(minutes_for_session, MINUTES);
	assertBuzzerOddSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());
	
	setTimerTime(minutes_for_session, MINUTES);
	assertBuzzerNanSession();
	TEST_ASSERT_EQUAL(REACHED, updatePomodoro());
}
