#include "unity.h"

#include "pomodoro_run.h"
#include "mock_timer.h"
#include "mock_handleLed.h"
#include "mock_buzzer.h"
#include "pomodoro_sessions.h"
#include <stdio.h>
long oneMinute = 1000*60;
void setUp(void)
{
	initTimer_Expect();
	openBuzzer_Expect();
	initHandleLed_Expect();
	newTimer_ExpectAndReturn(NULL);
	initRun();
	initSessions();
	setSessions(1,2,1);
}

void tearDown(void)
{
	destroyTimer_Ignore();
	closeBuzzer_Ignore();
	destroyHandleLed_Ignore();
	destroyRun();
}
void setMillisecondsToTime(double time)
{
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, time);
}
void assertWorkCicle(double wc)
{
	updateLed_ExpectAndReturn(wc,1);
}
void test_init_pomodoro_run(void)
{
	setMillisecondsToTime(oneMinute*0.5);
	assertWorkCicle(50);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}
void test_session_unreached_0_percent_time(void)
{
	setMillisecondsToTime(0);
	assertWorkCicle(0);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}
void test_session_unreached(void)
{
	setMillisecondsToTime(oneMinute*0.6);
	assertWorkCicle(60);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}

void assertReachedOddBuzzer(void)
{
	buzzer_Expect(2, 400);
}
void assertReachedEvenBuzzer(void)
{
	buzzer_Expect(4, 100);
}
void assertReinitTimer(void)
{
	reinitTimer_Expect(NULL);
}
void test_session_reached_100_percet_work_cicle(void)
{
	setMillisecondsToTime(oneMinute*1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}

void test_advance_session(void)
{
	setMillisecondsToTime(oneMinute*1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	pomodoro_run();

	setMillisecondsToTime(oneMinute*0 + 49);
	assertWorkCicle(0.0408333);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}

void test_on_interrupt_call_save_time_and_resume_after(void)
{
	setMillisecondsToTime(oneMinute*0.5);
	assertWorkCicle(50);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());

	setMillisecondsToTime(oneMinute*0.5+50);
	assertWorkCicle(50);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}

void test_buzzer_session_odd_two_long_buzz(void)
{
	setMillisecondsToTime(oneMinute);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}

void test_buzzer_session_even_four_short_buzz(void)
{
	setMillisecondsToTime(1*oneMinute);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	pomodoro_run();

	setMillisecondsToTime(2*oneMinute);
	assertWorkCicle(100);
	assertReachedEvenBuzzer();
	assertReinitTimer();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}
 
void test_on_end_all_sessions_return_POWEROFF_buzz_to_long(void)
{
	setMillisecondsToTime(1*oneMinute);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	pomodoro_run();
	setMillisecondsToTime(2*oneMinute);
	assertWorkCicle(100);
	assertReachedEvenBuzzer();
	assertReinitTimer();
	pomodoro_run();
	setMillisecondsToTime(1*oneMinute);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	pomodoro_run();

	setMillisecondsToTime(0);
	assertWorkCicle(NAN);
	buzzer_Expect(1,1000);
	TEST_ASSERT_EQUAL(ACTION_REACHED, pomodoro_run());
}

void test_on_time_cero_calculate_cero_workcicle(void)
{
	setMillisecondsToTime(0);
	assertWorkCicle(0);
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());
}

void test_reinit_timer_reached_session(void)
{
	setMillisecondsToTime(oneMinute*1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	assertReinitTimer();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_run());

}
