#ifndef INPUT_H
#define INPUT_H
#include "button.h"
#include "pomodoro_data.h"
typedef enum Input{INPUT_NOCHANGE = 0, INPUT_TOGGLE}INPUT;
void input_init(Button *, Pomodoro *);
void input_update(void);
#endif // INPUT_H
