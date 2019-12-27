#include "unity.h"

#include "pomodoro_run.h"
#include "mock_timer.h"
#include "mock_handleLed.h"
#include "mock_buzzer.h"
#include "pomodoro_sessions.h"

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
void setTimeToGet(double time)
{
	getTimer_ExpectAndReturn(NULL, MINUTES, time);
}
void assertWorkCicle(double wc)
{
	updateLed_ExpectAndReturn(wc,1);
}
void test_init_run(void)
{
	setTimeToGet(0.5);
	assertWorkCicle(50);
	TEST_ASSERT_EQUAL(RUNNING, run(ON));
}

void test_on_parameter_off_return_off(void)
{
	pauseTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(PAUSE, run(OFF));
}

void test_session_unreached(void)
{
	setTimeToGet(0.5);
	assertWorkCicle(50);
	TEST_ASSERT_EQUAL(RUNNING, run(ON));
}

void assertReachedOddBuzzer(void)
{
	buzzer_Expect(2, 400);
}
void assertReachedEvenBuzzer(void)
{
	buzzer_Expect(4, 100);
}
void test_session_reached(void)
{
	setTimeToGet(1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	TEST_ASSERT_EQUAL(REACHED, run(ON));
}

void test_advance_session(void)
{
	setTimeToGet(1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	run(ON);

	setTimeToGet(1.5);
	assertWorkCicle(75);
	TEST_ASSERT_EQUAL(RUNNING, run(ON));
}

void test_on_parameter_off_pause_timer(void)
{
	pauseTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(PAUSE, run(OFF));
}

void test_buzzer_session_odd_two_long_buzz(void)
{
	setTimeToGet(1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	TEST_ASSERT_EQUAL(REACHED, run(ON));
}

void test_buzzer_session_even_four_short_buzz(void)
{
	setTimeToGet(1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	run(ON);
	setTimeToGet(2);
	assertWorkCicle(100);
	assertReachedEvenBuzzer();
	TEST_ASSERT_EQUAL(REACHED, run(ON));
}

void test_on_end_all_sessions_return_POWEROFF_buzz_to_long(void)
{
	setTimeToGet(1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	run(ON);
	setTimeToGet(2);
	assertWorkCicle(100);
	assertReachedEvenBuzzer();
	run(ON);
	setTimeToGet(1);
	assertWorkCicle(100);
	assertReachedOddBuzzer();
	run(ON);
	setTimeToGet(0);
	assertWorkCicle(NAN);
	buzzer_Expect(1,1000);
	TEST_ASSERT_EQUAL(POWEROFF, run(ON));
}

void test_resume_timer_after_pause(void)
{
	pauseTimer_Expect(NULL);
	run(OFF);
	resumeTimer_Expect(NULL);
	setTimeToGet(0.5);
	assertWorkCicle(50);
	TEST_ASSERT_EQUAL(RUNNING, run(ON));
}

void test_on_time_cero_calculate_cero_workcicle(void)
{
	setTimeToGet(0);
	assertWorkCicle(0);
	TEST_ASSERT_EQUAL(RUNNING, run(ON));
}
