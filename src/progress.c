#include "progress.h"
int progress_update(const Session session)
{
	double proportion  = (session.session_time - session.acumulated_time)
		/ session.session_time;
	double progress = 1 - proportion;
	return 100*(progress);
}
