#include "unity.h"
#include "../src/progress.h"
#include "../src/session.h"

Session session;
void setUp(void)
{
}

void tearDown(void)
{
}

void test_calculate_progress_at_init(void)
{
	session.session_time = 5;
	session.acumulated_time = 0;

	TEST_ASSERT_EQUAL(0, progress_update(session));
}

void test_calculate_progress_at_fiven_time_for_five_minutes(void)
{
	session.session_time = 5;
	session.acumulated_time = 2.5;

	TEST_ASSERT_EQUAL(50, progress_update(session));
}
