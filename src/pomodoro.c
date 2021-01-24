#include"pomodoro.h"
#include"millis.h"

static Pomodoro *pomodoro;

static void addTime(uint32_t actual, uint32_t *last, double *output_minutes);
static void compute_progress(Session session, int *progress);

void pomodoro_init(Pomodoro *pomodoro_object)
{
	pomodoro = pomodoro_object;
	pomodoro->session.current_time = 0;
	pomodoro->time.last = 0;
}

void pomodoro_update(void)
{
	addTime(millis(), &pomodoro->time.last, &pomodoro->session.current_time);
	compute_progress(pomodoro->session, &pomodoro->progress);
}

static void addTime(uint32_t actual, uint32_t *last, double *output_minutes)
{
	uint32_t time_from_past = actual-*last;
	*output_minutes += time_from_past/60000.0;
	*last = actual;
}

static void compute_progress(Session session, int *progress)
{
	*progress =100*(1-(session.session_time - session.current_time)/
		session.session_time);
}

//get's and set's
double pomodoro_getProgress(Pomodoro * pomodoro)
{
	return pomodoro->progress ;
}
