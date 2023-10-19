#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void button_init(void);
bool button_pushed(void);

#ifdef __cplusplus
}
#endif

#endif // BUTTON_H
