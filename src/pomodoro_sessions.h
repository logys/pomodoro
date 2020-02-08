#ifndef POMODORO_SESSIONS_H
#define POMODORO_SESSIONS_H
#include<math.h>

#define setSessions(...) setSession((double[]){__VA_ARGS__, NAN})
void setSession(double const time[]);
double getSessionTime(void);
short getSessionNumber(void);
void advanceSession(void);
void reinitSessions(void);
void initSessions(void);
void destroySessions(void);
#endif // POMODORO_SESSIONS_H
