#ifndef _EVENT_INPUT_H
#define _EVENT_INPUT_H
#include <stdint.h>
enum {NONE = 0, PLAY_PAUSE, POWEROFF};
void initEventInput(void);
int8_t readEvent(void);
void destroyEventInput(void);

#endif // _EVENT_INPUT_H
