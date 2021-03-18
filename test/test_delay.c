//#ifdef TEST

#include "unity.h"

#include "delay.h"
#include "fff.h"
#include <stdint.h>

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint32_t, millis)

void setUp(void)
{
}

void tearDown(void)
{
}

void test_return_when_reached_time(void)
{
	millis_fake.return_val = 50;

	//delay(50);

	TEST_ASSERT(millis_fake.call_count);
}

//#endif // TEST
