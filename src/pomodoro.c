#include"pomodoro.h"
#include"millis.h"

static Pomodoro *pomodoro;

void addTime(uint32_t actual, uint32_t *last, double *output_minutes);
static void compute_progress(Session session, int *progress);

void pomodoro_init(Pomodoro *pomodoro_input)
{
	pomodoro = pomodoro_input;
	pomodoro->session.current_time = 0;
}
void pomodoro_update(void)
{
	addTime(pomodoro->time.current, &pomodoro->time.last, &pomodoro->session.current_time);
	compute_progress(pomodoro->session, &pomodoro->progress);
}
void addTime(uint32_t actual, uint32_t *last, double *output_minutes)
{
	uint32_t time_from_past = actual-*last;
	*output_minutes += time_from_past/60000.0;
}
static void compute_progress(Session session, int *progress)
{
	*progress =100*(1-(session.session_time - session.current_time)/
		session.session_time);
}
double pomodoro_getProgress(void)
{
	return 0 ;
}
