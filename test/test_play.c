#include "unity.h"

#include "../src/action.h"
#include "../src/play.h"
#include "progress_spy.h"

Action play;
void setUp(void)
{
	play = play_create();
}

void tearDown(void)
{
}

void test_progress_cero(void)
{
	int progress = play.action_do(&play);
	TEST_ASSERT_EQUAL(0, progress);
}
