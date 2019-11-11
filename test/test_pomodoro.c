#include "unity.h"
#include <math.h>
#include "pomodoro.h"
#include "mock_timer.h"
#include "mock_event_input.h"
#include "mock_handleLed.h"
#include "mock_buzzer.h"
#include "mock_apagar.h"

void setUp(void)
{
	initTimer_Expect();
	initEventInput_Expect();
	initHandleLed_Expect();
	openBuzzer_Expect();
	newTimer_ExpectAndReturn(NULL);
	initPomodoro();
}

void tearDown(void)
{
}

void test_if_no_sessions_update_off(void)
{
	//set no sessions
	double time_sessions = NAN;
	setTimer_Expect(NULL, time_sessions, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(time_sessions);

	readEvent_ExpectAndReturn(NONE);
	float time_returned_from_timer = 5;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	apagar_Expect();
	reinitTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(OFF, actualizar());
}

void test_set_sessions_unreached_session_time(void)
{
	double time_sessions = 5;
	setTimer_Expect(NULL, time_sessions, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(time_sessions);

	readEvent_ExpectAndReturn(NONE);
	getTimer_ExpectAndReturn(NULL, MINUTES, 0);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(0);
	TEST_ASSERT_EQUAL(ON, actualizar());
}

void assertSetsession(int8_t time);
void test_near_of_finish_99_percent(void)
{
	int8_t time_sessions = 5;
	assertSetsession(time_sessions);

	readEvent_ExpectAndReturn(NONE);
	double time_returned_from_timer = 4.95;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(99);
	TEST_ASSERT_EQUAL(ON, actualizar());

}
void assertSetsession(int8_t time)
{
	setTimer_Expect(NULL, time, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(time);
}

void test_reached_time_session_call_buzzer(void)
{
	int8_t time_sessions = 5;
	assertSetsession(time_sessions);

	readEvent_ExpectAndReturn(NONE);
	float time_returned_from_timer = 5;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(100);
	buzzer_Expect(2, 500);//2 slow beep
	setTimer_Ignore();
	TEST_ASSERT_EQUAL(ON, actualizar());
}

void assertReachedFirstSession(void);
void test_on_reached_change_next_sesion(void)
{
	float session1 = 5,
	      session2 = 1;
	setTimer_Expect(NULL, session1, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(session1, session2);

	assertReachedFirstSession();

	//second session
	readEvent_ExpectAndReturn(NONE);
	float time_returned_from_timer = 0.5;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(50);
	TEST_ASSERT_EQUAL(ON, actualizar());
}
void assertReachedFirstSession(void)
{
	float session2 = 1;
	readEvent_ExpectAndReturn(NONE);
	float time_returned_from_timer = 5;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(100);
	buzzer_Expect(2, 500);
	setTimer_Expect(NULL, session2, MINUTES);
	setTimer_IgnoreArg_timer();
	TEST_ASSERT_EQUAL(ON, actualizar());
}
void assertSet2Sessions(void);
void test_reached_rest_time_buzzer_fast(void)
{
	assertSet2Sessions();
	assertReachedFirstSession();

	//second session reached
	readEvent_ExpectAndReturn(NONE);
	float time_returned_from_timer = 1;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(100);
	buzzer_Expect(5, 100);
	setTimer_Expect(NULL, NAN, MINUTES);
	setTimer_IgnoreArg_timer();
	TEST_ASSERT_EQUAL(ON, actualizar());
}
void assertSet2Sessions(void)
{
	float session1 = 5,
	      session2 = 1;
	setTimer_Expect(NULL, session1, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(session1, session2);
}

void test_set_more_sessions_than_maximun(void)
{
	//set many sessions
	setTimer_Expect(NULL, 3, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3);

	//reached maximun MAX_SESIONES sessions
	for(int i = 0; i < MAX_SESIONES; i++){
		readEvent_ExpectAndReturn(NONE);
		float time_returned_from_timer = 3;
		getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
		getTimer_IgnoreArg_timer();
		writeToLed_Expect(100);
		if(i%2 == 0)
			buzzer_Expect(2, 500);
		else
			buzzer_Expect(5, 100);
		if( i < MAX_SESIONES -1){
			setTimer_Expect(NULL, 3, MINUTES);
			setTimer_IgnoreArg_timer();
		}else{ //last session, no reset timer, session 10
			setTimer_Expect(NULL, NAN, MINUTES);
			setTimer_IgnoreArg_timer();
		}
		TEST_ASSERT_EQUAL(ON, actualizar());
	}
}

void test_set_nan_session(void)
{
	setTimer_Expect(NULL, NAN, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(NAN);
}

void test_shutdown_on_nan_sesion(void)
{
	setTimer_Expect(NULL, NAN, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(NAN);

	readEvent_ExpectAndReturn(POWEROFF);
	float time_returned_from_timer = 5;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	apagar_Expect();
	reinitTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(OFF, actualizar());
}

void test_shutdown_on_POWEROFF_event(void)
{
	float session1 = 10;
	setTimer_Expect(NULL, session1, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(session1);

	readEvent_ExpectAndReturn(POWEROFF);
	float time_returned_from_timer = 5;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	apagar_Expect();
	reinitTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(OFF, actualizar());
}

void test_reinit_after_poweroff(void)
{
	//set two sessions
	float session1 = 10;
	float session2 = 20;
	setTimer_Expect(NULL, session1, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(session1, session2);

	//get power off from button
	readEvent_ExpectAndReturn(POWEROFF);
	float time_returned_from_timer = session1;
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	apagar_Expect();
	reinitTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(OFF, actualizar());

	//after shutdown the pomodoro reinit to first session and after this
	//finish reset timer to second session
	readEvent_ExpectAndReturn(NONE);
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(100);
	buzzer_Expect(2, 500);
	setTimer_Expect(NULL, 20, MINUTES);
	setTimer_IgnoreArg_timer();
	TEST_ASSERT_EQUAL(ON, actualizar());
}

void test_toggle_play_pause_timer(void)
{	
	//set 3 sessions
	float session1 = 25;
	setTimer_Expect(NULL, session1, MINUTES);
	setTimer_IgnoreArg_timer();
	setSesiones(session1, 10, 25);

	//only toggle play/pause
	float time_returned_from_timer = session1/3;
	readEvent_ExpectAndReturn(PLAY_PAUSE);
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	pauseTimer_Expect(NULL);
	pauseTimer_IgnoreArg_timer();
	TEST_ASSERT_EQUAL(ON, actualizar());

	//handle pause
	readEvent_ExpectAndReturn(NONE);
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	writeToLed_Expect(50);
	TEST_ASSERT_EQUAL(ON, actualizar());

	//only toggle play/pause
	time_returned_from_timer = session1/3;
	readEvent_ExpectAndReturn(PLAY_PAUSE);
	getTimer_ExpectAndReturn(NULL, MINUTES, time_returned_from_timer);
	getTimer_IgnoreArg_timer();
	resumeTimer_Expect(NULL);
	resumeTimer_IgnoreArg_timer();
	TEST_ASSERT_EQUAL(ON, actualizar());
}
