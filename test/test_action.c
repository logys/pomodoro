#include "unity.h"

#include "action.h"

void setUp(void)
{
	initAction();
}

void tearDown(void)
{
}

void test_init_action_as_poweroff(void)
{
	initAction();
	TEST_ASSERT_EQUAL(*action, NULL);
}
