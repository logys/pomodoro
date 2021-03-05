#ifndef SESSION_H
#define SESSION_H

#include <stdbool.h>

typedef struct Session{
	double progress;
	bool finished;

	int session_time;
	double acumulated_time;
	double current_time;
}Session;

#endif // SESSION_H
