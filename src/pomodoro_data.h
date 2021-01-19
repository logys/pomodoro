#ifndef POMODORO_DATA_H
#define POMODORO_DATA_H
#include "session.h"
#include "time.h"
typedef enum Pomodoro_action{ACTION_PLAY = 0}POMODORO_ACTION;
typedef struct Pomodoro{
	short input;
	POMODORO_ACTION action;
	int progress;
	int session_time;
	double acumulated_time;
	double actual_time;
	Session session;
	Time time;
}Pomodoro;
#endif// POMODORO_DATA_H
