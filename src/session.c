#include "session.h"

void session_setCurrentTime(Session *session, double time)
{
	session->current_time = time;
}
void session_setSessionTime(Session *session, int time)
{
	session->session_time = time;
}
double session_getCurrentTime(Session *session)
{
	return session->current_time;
}
