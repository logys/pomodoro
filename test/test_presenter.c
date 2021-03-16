#include "unity.h"
#include "fff.h"
#include "presenter.h"
#include <stdbool.h>

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(ledController_init);
FAKE_VOID_FUNC(poweroff_init);
FAKE_VOID_FUNC(buzzerController_init);
FAKE_VOID_FUNC(reboundHandler_init);
FAKE_VOID_FUNC(ledController_do);
FAKE_VOID_FUNC(buzzerController_do);
FAKE_VOID_FUNC(reboundHandler_do);

bool button;
short progress;
bool finished;

void setUp(void)
{
	presenter_init(1, 2, 3, &button, &progress, &finished);
}

void tearDown(void)
{
}

void test_init_led(void)
{
	TEST_ASSERT(ledController_init_fake.call_count);
}
