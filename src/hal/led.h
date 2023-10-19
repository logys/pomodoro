#ifndef LED_H
#define LED_H
#ifdef __cplusplus
extern "C" {
#endif
void led_init(void);
void led_toggle(void);
void led_blink(void);
void led_blink_slow(void);
#ifdef __cplusplus
}
#endif
#endif// LED_H
