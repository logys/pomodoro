//#ifdef TEST

#include "unity.h"

#include "../src/buzzerController.h"
#include "fff.h"
#include <stdbool.h>

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(buzzer_on);
FAKE_VOID_FUNC(buzzer_off);
FAKE_VOID_FUNC(buzzer_open);
FAKE_VOID_FUNC(delay);

bool finished;

void setUp(void)
{
	finished = false;
	buzzerController_init(1, &finished);
	RESET_FAKE(buzzer_on);
}

void tearDown(void)
{
}

void test_buzz_if_finished(void)
{
	finished = true;

	buzzerController_do();

	TEST_ASSERT_EQUAL(2, buzzer_on_fake.call_count);
}

void test_buzz_if_not_finished(void)
{
	finished = false;

	buzzerController_do();

	TEST_ASSERT_FALSE(buzzer_on_fake.call_count);
}


//#endif // TEST
