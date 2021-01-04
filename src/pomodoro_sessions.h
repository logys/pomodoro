#ifndef POMODORO_SESSIONS_H
#define POMODORO_SESSIONS_H
#include<math.h>
#include<stdbool.h>

void sessions_init(void);
void sessions_destroy(void);
double sessions_getSessionTime(void);
short sessions_getSessionNumber(void);
void sessions_advanceSession(void);
void sessions_reinitIndex(void);
//Sesiones en forma de lista, i.e. sessions_set(1,2,1,2);
#define sessions_set(...) setSession((double []){__VA_ARGS__, NAN})
bool setSession(double const time[]);
#endif // POMODORO_SESSIONS_H
