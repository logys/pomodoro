#include "progress.h"
int progress_update(const Session session)
{
	return 100*(1-(session.session_time - session.acumulated_time)/
		       session.session_time);
}
