#include "action.h"
#include "progress.h"
Session sess;
Session *sessio = &sess;
double play_do(Action *);

Action play_create(void)
{
	Action tmp;
	tmp.action_do = play_do;
	return tmp;
}

double play_do(Action * action)
{
	return progress_update(*sessio);;
}
