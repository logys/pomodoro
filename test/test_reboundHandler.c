//#ifdef TEST

#include "unity.h"

#include "../src/reboundHandler.h"
#include <stdbool.h>
#include <assert.h>
#include "fff.h"

static void toReboundZone(void);
static void toDirectRead(void);

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(bool, button_read);
FAKE_VALUE_FUNC(double, timer_getTime);
FAKE_VOID_FUNC(timer_reset);

bool pushed;

void setUp(void)
{
	pushed = false;
	reboundHandler_init(2, &pushed);
	RESET_FAKE(button_read);
	RESET_FAKE(timer_getTime);
}

void tearDown(void)
{
}

void test_pushed_on_flanc(void)
{
	pushed = false;
	button_read_fake.return_val = true;

	reboundHandler_do();

	TEST_ASSERT(pushed);
}

void test_no_pushed(void)
{
	pushed = true;
	button_read_fake.return_val = false;
	
	reboundHandler_do();

	TEST_ASSERT_FALSE(pushed);
}

void test_pushed_50ms_after_flanc(void)
{
	toReboundZone();
	pushed = false;
	button_read_fake.return_val = false;
	timer_getTime_fake.return_val = 50;

	reboundHandler_do();

	TEST_ASSERT(pushed);
}

void test_direct_read_after_50ms_unpushed(void)
{
	toDirectRead();
	pushed = true;
	button_read_fake.return_val = false;

	reboundHandler_do();

	TEST_ASSERT_FALSE(pushed);

}

void test_direct_read_after_50ms_pushed(void)
{
	toDirectRead();
	pushed = false;
	button_read_fake.return_val = true;

	reboundHandler_do();

	TEST_ASSERT(pushed);
}

static void toReboundZone(void)
{
	button_read_fake.return_val = true;
	reboundHandler_do();
	assert(pushed);
}

static void toDirectRead(void)
{
	toReboundZone();
	timer_getTime_fake.return_val = 51;
	reboundHandler_do();
	assert(pushed);
}
//#endif // TEST
