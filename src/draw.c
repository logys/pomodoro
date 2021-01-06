#include "draw.h"
struct{
	Led *led;
}draw;
void draw_init(Led * led, Buzzer *buzzer)
{
	draw.led = led;
}
void draw_update(void)
{
	led_toggle(draw.led);
}
