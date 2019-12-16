#include "unity.h"
#include "pomodoro_sessions.h"

void setUp(void)
{
	initSessions();
}

void tearDown(void)
{
}

void test_no_set_sessions_set_NAN(void)
{
	TEST_ASSERT(isnan(getSessionTime()));
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

	setSessions(minutes);
}
void assertSesionMinutes(double minutes)
{
	setOneSessionInMinutes(minutes);
	TEST_ASSERT_EQUAL(minutes, getSessionTime());
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
	setSessions(time_session_one, time_session_two);

	TEST_ASSERT_EQUAL(time_session_one, getSessionTime());
	advanceSession();
	TEST_ASSERT_EQUAL(time_session_two, getSessionTime());
}

void test_add_NAN_after_last_session(void)
{
	short time_session_one = 1,
	      time_session_two = 2;
	setSessions(time_session_one, time_session_two);
	advanceSession();
	advanceSession();
	TEST_ASSERT(isnan(getSessionTime()));
}

void test_nan_session_eleven(void)
{
	setSessions(1);
	for(short i = 0; i<10; i++)
		advanceSession();
	TEST_ASSERT(isnan(getSessionTime()));
}

void test_max_sessions_ten(void)
{
	short session_ten_in_minutes = 7;
	setSessions(1,1,1,1,0,2,3,4,5, session_ten_in_minutes,8,3,1,1,2,3,4,5,6,7,8,9);
	for(short i = 0; i<9; i++)
		advanceSession();
	TEST_ASSERT_EQUAL(session_ten_in_minutes, getSessionTime());
	advanceSession();
	TEST_ASSERT(isnan(getSessionTime()));
}
