#ifndef _EVENT_INPUT_H
#define _EVENT_INPUT_H
#include <stdint.h>
typedef enum {NONE = 0, PLAY_PAUSE, POWEROFF}EVENT;

void eventInput_create(void);
EVENT eventInput_read(void);
void eventInput_destroy(void);

#endif // _EVENT_INPUT_H
