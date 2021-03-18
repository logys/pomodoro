#include "unity.h"
#include "fff.h"
#include "../src/presenter.h"
#include "../src/blinker.h"
#include "../src/timer.h"
#include <stdbool.h>
#include <stdint.h>

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(poweroff_init);
FAKE_VOID_FUNC(buzzerController_init);
FAKE_VOID_FUNC(reboundHandler_init);
FAKE_VOID_FUNC(buzzerController_do);
FAKE_VOID_FUNC(reboundHandler_do);
FAKE_VOID_FUNC(led_open);
FAKE_VOID_FUNC(led_toggle);
FAKE_VOID_FUNC(poweroff);
FAKE_VOID_FUNC(millis_init);
FAKE_VALUE_FUNC(uint32_t, millis);

bool button;
short progress;
bool finished;

void setUp(void)
{
	RESET_FAKE(led_toggle);

	presenter_init(6, 3, &button, &finished);
	blinker_init(&progress);
}

void tearDown(void)
{
}

void test_toggle_fast(void)
{
	progress = 100;

	for(int i = 0; i<1000; i++){
		millis_fake.return_val += 1;
		presenter_do();
	}

	TEST_ASSERT_EQUAL(125, led_toggle_fake.call_count);
}
