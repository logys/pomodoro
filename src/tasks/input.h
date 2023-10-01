#ifndef INPUT_HPP
#define INPUT_HPP

#include <stdbool.h>
#include "pomodoro.h"
#include <stdint.h>

typedef struct{
	bool last_pushed;
	uint32_t time_ms;
}Input;

#ifdef __cplusplus
extern "C" {
#endif

void input_init(void);
void input_doIt(void);
Input input_create(void);
void input_do(Input * input, Pomodoro * pomodoro);

#ifdef __cplusplus
}
#endif

#endif// INPUT_HPP
