#include "pomodoro_sessions.h"
#include <math.h>
#define MAX_SESSIONS 11
struct Session{
	short index;
	double session_time[MAX_SESSIONS];
};

static struct Session session;

void sessions_init(void)
{
	session.index = 0;
	session.session_time[0] = NAN;
	session.session_time[MAX_SESSIONS-1] = NAN;
}

static void addSession(short index, double time);
bool setSession(double const time[])
{
	short i;
	for(i = 0; (!isnan(time[i])) && (i<(MAX_SESSIONS-1)); i++)
		addSession(i, time[i]);
	session.session_time[i] = NAN;
	return true;
}
static void addSession(short index, double time)
{
	session.session_time[index] = time;	
}

double sessions_getSessionTime(void)
{
	return session.session_time[session.index];
}

void sessions_advanceSession(void)
{
	session.index++;
}
void sessions_reinitIndex(void)
{
	session.index = 0;
}

short sessions_getSessionNumber(void)
{
	return session.index + 1;
}
void sessions_destroy(void)
{
}
