#include "unity.h"

#include "../src/button_driver.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(async_button_determine_action);

void setUp(void)
{
}

void tearDown(void)
{
}

/*
void test_on_push_call_determineAction(void)
{


	TEST_ASSERT(async_button_determine_action_fake.call_count == 1);
}
*/
