#include <ncurses.h>
#include <unistd.h>  // para usleep
		     //
static void setWakeUp(void);
static void enableAutoWakeup(void);
static void disableAutoWakeup(void);
static void setExternalInterruptWakeup(void);
enum STATE{OFF, ON};
static uint8_t state;
void powermode_init(void)
{
	state = OFF;
}

static void setExternalInterruptWakeup(void)
{
}

static void setWakeUp(void)
{
}

static void enableAutoWakeup(void)
{
}

void powermode_standBy(void)
{
	state = OFF;
}

static void disableAutoWakeup(void)
{
}

static void toggle_power(void)
{
	state = state ? OFF : ON;
}

void powermode_sleep(void)
{
	while(state = OFF){
		if(getch() == 'z')
	 		toggle_power();
	}
	usleep(5000);
}
