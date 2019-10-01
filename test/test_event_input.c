#include "unity.h"
#include "event_input.h"
#include "mock_entrada.h"

void setUp(void)
{
	openPush_Ignore();
	initEventInput();
}

void tearDown(void)
{
}

void test_event_none(void)
{
	readPush_ExpectAndReturn(0);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_no_push(void)
{
	readPush_ExpectAndReturn(0);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_one_push_fast(void)
{
	readPush_ExpectAndReturn(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());
}
