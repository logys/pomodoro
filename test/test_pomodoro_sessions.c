#include "unity.h"
#include "../src/pomodoro_sessions.h"


void setUp(void)
{
	sessions_init();
}

void tearDown(void)
{
}

void test_no_set_sessions_set_NAN(void)
{
	TEST_ASSERT(isnan(sessions_getSessionTime()));
}

void setOneSessionInMinutes(double minutes);
void assertSesionMinutes(double minutes);
void test_sesion_1_minuto(void)
{
	double sesion_time_minutes = 1;
	assertSesionMinutes(sesion_time_minutes);
}
void setOneSessionInMinutes(double minutes)
{

	setSession((double []){minutes});
}
void assertSesionMinutes(double minutes)
{
	setOneSessionInMinutes(minutes);
	TEST_ASSERT_EQUAL(minutes, sessions_getSessionTime());
}

void test_session_20_minutes(void)
{
	double sesion_time_minutes = 20;
	assertSesionMinutes(sesion_time_minutes);
}

void test_two_sessions_one_minute(void)
{
	short time_session_one = 1,
	      time_session_two = 2;
	setSession((double[]){time_session_one, time_session_two});

	TEST_ASSERT_EQUAL(time_session_one, sessions_getSessionTime());
	sessions_advanceSession();
	TEST_ASSERT_EQUAL(time_session_two, sessions_getSessionTime());
}

void test_add_NAN_after_last_session(void)
{
	short time_session_one = 1,
	      time_session_two = 2;
	sessions_set(time_session_one, time_session_two);
	sessions_advanceSession();
	sessions_advanceSession();
	TEST_ASSERT(isnan(sessions_getSessionTime()));
}
void test_nan_session_eleven(void)
{
	setSession((double[]){1});
	for(short i = 0; i<10; i++)
		sessions_advanceSession();
	TEST_ASSERT(isnan(sessions_getSessionTime()));
}
void test_max_sessions_ten(void)
{
	short session_ten_in_minutes = 7;
	setSession((double []){1,1,1,1,0,2,3,4,5, session_ten_in_minutes,8,3,1,1,2,3,4,5,6,7,8,9});
	for(short i = 0; i<9; i++)
		sessions_advanceSession();
	TEST_ASSERT_EQUAL(session_ten_in_minutes, sessions_getSessionTime());
	sessions_advanceSession();
	TEST_ASSERT(isnan(sessions_getSessionTime()));
}
void test_reinit_sessions(void)
{
	sessions_advanceSession();
	sessions_advanceSession();
	sessions_advanceSession();
	sessions_reinitIndex();
	TEST_ASSERT_EQUAL(1, sessions_getSessionNumber());
}

