#include "unity.h"

#include "pomodoro_poweroff.h"
#include "pomodoro_sessions.h"
#include "led.h"
#include "mock_stub_sleep.h" 
#include "mock_stub_interrupt.h" 

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sleep_chan(void)
{
	set_sleep_mode_Expect(SLEEP_MODE_PWR_DOWN);
	cli_ExpectAndReturn(0);
	sleep_enable_Expect();
	sleep_bod_disable_Expect();
	sei_ExpectAndReturn(0);
	sleep_cpu_Expect();
	sleep_disable_Expect();
	sei_ExpectAndReturn(0);
	pomodoro_off();
}
