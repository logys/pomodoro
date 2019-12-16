#include "pomodoro_sessions.h"
#define MAX_SESSIONS 11
struct Session{
	short index;
	double session_time[MAX_SESSIONS];
};

static struct Session session;

void initSessions(void)
{
	session.index = 0;
	session.session_time[0] = NAN;
	session.session_time[MAX_SESSIONS-1] = NAN;
}

static void addSession(short index, double time);
void setSession(double const time[])
{
	short i;
	for(i = 0; (!isnan(time[i])) && (i<(MAX_SESSIONS-1)); i++)
		addSession(i, time[i]);
	session.session_time[i] = NAN;
}
static void addSession(short index, double time)
{
	session.session_time[index] = time;	
}

double getSessionTime(void)
{
	return session.session_time[session.index];
}

void advanceSession()
{
	session.index++;
}

short getSessionNumber(void)
{
	return session.index + 1;
}
