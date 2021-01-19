#ifndef SESSION_H
#define SESSION_H
typedef struct Session{
	int session_time;
	double current_time;
}Session;
void session_setCurrentTime(Session *, double time);
void session_setSessionTime(Session *, int time);
double session_getCurrentTime(Session *);
//double session_getSessionTime(Session *);
#endif // SESSION_H
