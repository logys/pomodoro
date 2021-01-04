#include "/home/antonio/.gem/ruby/gems/ceedling-0.30.0/vendor/unity/src/unity.h"
#include "../src/pomodoro.h"
#include "../src/pomodoro_sessions.h"
#include "spy_time.h"
#include "spy_buzzer.h"
#include "spy_led.h"
#include "../src/led.h"
#include "avr/io.h"
int sessions;
void setUp(void)
{
	Led led;
	led_create(&led, PIN_LED);
	pomodoro_init(&led, NULL, NULL);
}
void tearDown(void)
{
	pomodoro_destroy();
}

//Unit
//sessions
void test_set_sessions(void)
{
	TEST_ASSERT(pomodoro_setSessions(0));
}
void test_set_one_minute_to_sessions(void)
{
	pomodoro_setSessions(1);
	TEST_ASSERT_EQUAL(1, sessions_getSessionNumber());
	TEST_ASSERT_EQUAL(1, sessions_getSessionTime());
}
void test_set_two_sessions_whit_three_minutes_in_seccond_place(void)
{
	pomodoro_setSessions(2, 3);
	sessions_advanceSession();
	TEST_ASSERT_EQUAL(2, sessions_getSessionNumber());
	TEST_ASSERT_EQUAL(3, sessions_getSessionTime());
}
void test_call_reset_index_sessions(void)
{
	pomodoro_setSessions(1,2,3,4);
	sessions_advanceSession();
	sessions_advanceSession();
	sessions_advanceSession();

	sessions_reinitIndex();
	TEST_ASSERT_EQUAL(1, sessions_getSessionNumber());
}
//PlaySessions
#include"spy_time.h"
void test_play_session_one_cero_time(void)
{
	pomodoro_setSessions(1,1);
	pomodoro_update();
	spy_addTimeMillis(0);
	TEST_ASSERT_EQUAL(0, spy_ledWrited());
}
void test_play_session_one_fifty_percent(void)
{
	pomodoro_setSessions(2);
	spy_addTimeMillis(60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL(50, spy_ledWrited());
}
void test_play_session_one_one_hundred_percent_and_call_buzz(void)
{
	pomodoro_setSessions(1, 2);
	spy_addTimeMillis(60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL(100, spy_ledWrited());
	TEST_ASSERT(spy_buzzerCalled());
}
void test_on_one_hundred_reinit_acummulated_time(void)
{
	pomodoro_setSessions(1, 2);
	spy_addTimeMillis(60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL(100, spy_ledWrited());

	spy_addTimeMillis(0);
	pomodoro_update();
	TEST_ASSERT_EQUAL(50, spy_ledWrited());
}
void test_one_hundrer_percent_init_a_pause(void)
{
	pomodoro_setSessions(1, 2);
	spy_addTimeMillis(60*1000);
	pomodoro_update();

	spy_addTimeMillis(0);
	pomodoro_update();
	//pause always write 50 to led
	TEST_ASSERT_EQUAL(50, spy_ledWrited());
}
/*
void test_on_one_hundred_advance_session(void)
{
	pomodoro_setSessions(1, 2);
	spy_addTimeMillis(60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL(2, sessions_getSessionNumber());
}
*/
//Aceptance
void test_get_progress_of_pomodoro_from_init(void)
{
	pomodoro_setSessions(1);
	pomodoro_update();
	spy_addTimeMillis(0);
	TEST_ASSERT_EQUAL(0, pomodoro_getProgress());
}
void test_get_progress_of_pomodoro_from_init_past_fifty_percent(void)
{
	pomodoro_setSessions(2);
	pomodoro_update();
	spy_addTimeMillis(60*1000);
	TEST_ASSERT_EQUAL(50, pomodoro_getProgress());
}

//Register pins
//PB1 buzzer on pin 6
void test_register_buzzer_pin(void)
{
	TEST_ASSERT(pomodoro_setPin(PIN_BUZZER, 6));
}
//PB2 led on pin 7
void test_register_led_pin(void)
{
	TEST_ASSERT(pomodoro_setPin(PIN_LED, 7));
}
//PB3 led on pin 2
void test_register_button_pin(void)
{
	TEST_ASSERT(pomodoro_setPin(PIN_BUTTON, 2));
}
void test_double_pin_registred(void)
{
	pomodoro_setPin(PIN_BUTTON, 2);
	TEST_ASSERT_FALSE(pomodoro_setPin(PIN_LED, 2));
}
void test_invalid_pin(void)
{
	TEST_ASSERT_FALSE(pomodoro_setPin(PIN_LED, 1));
	TEST_ASSERT_FALSE(pomodoro_setPin(PIN_LED, 4));
	TEST_ASSERT_FALSE(pomodoro_setPin(PIN_LED, 8));
	TEST_ASSERT_FALSE(pomodoro_setPin(PIN_LED, 0));
	TEST_ASSERT_FALSE(pomodoro_setPin(PIN_LED, 9));
}

//Poweroff
#include "spy_poweroff.h"
void test_poweroff_called(void)
{
	TEST_ASSERT(spy_poweroff_called());
}
