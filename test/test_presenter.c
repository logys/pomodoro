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
FAKE_VOID_FUNC(led_open);
FAKE_VOID_FUNC(blinker_do);
FAKE_VOID_FUNC(poweroff);

bool button;
short progress;
bool finished;

void setUp(void)
{
	presenter_init(6, 3, &button, &progress, &finished);
}

void tearDown(void)
{
}
