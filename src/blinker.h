#ifndef BLINKER_H
#define BLINKER_H

void blinker_init(short const led_pin, short const * const progress);
void blinker_do(void);

#endif // BLINKER_H
