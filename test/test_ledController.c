//#ifdef TEST

#include "unity.h"

#include "../src/ledController.h"

#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(led_open);
FAKE_VOID_FUNC(led_off);
FAKE_VOID_FUNC(blinker_do);
FAKE_VOID_FUNC(blinker_init);

bool finished;
short progress;

void setUp(void)
{
	ledController_init(1, &finished, &progress);
}

void tearDown(void)
{
}

void test_call_to_led_function(void)
{
	finished = false;

	ledController_do();

	TEST_ASSERT(blinker_do_fake.call_count);
}

void test_if_finished_ligh_off(void)
{
	finished = true;

	ledController_do();

	TEST_ASSERT(led_off_fake.call_count);
}

//#endif // TEST
