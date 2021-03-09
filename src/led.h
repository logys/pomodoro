#ifndef LED_H
#define LED_H

typedef struct Led{
	short pin;
}Led;
void led_create(Led *, short pin);
void led_blink_rate(Led *, short rate);
void led_toggle(Led *);

/** \file drivers.h 
 * \brief 
 * Drivers, para buzzer, led y pushbuttons*/
/** \brief Inicia el LED*/
void led_open(void);
/** Detiene LED*/
void led_close(void);
void led_on(void);
void led_off(void);
/** \brief Toggle */
void toggleLed(Led *);

void led_init(const short led);
#endif //LED_H
