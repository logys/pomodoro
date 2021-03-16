#include "reboundHandler.h"
#include "buzzer.h"
#include "button.h"
#include "timer.h"

typedef enum{WAITING_FLANC, REBOUND_ZONE, DIRECT_READ}STATE;

static void waitingFlanc(void);
static void reboundZone(void);
static void directRead(void);

static bool * button;
static CLOCK timer;
static STATE current_state;


static void (*state_table[])(void) = {
	waitingFlanc,
	reboundZone,
	directRead
};


void reboundHandler_init(short const button_pin, bool * const button_state)
{
	button = button_state;
	current_state = WAITING_FLANC;

	button_open(button_pin);
}

void reboundHandler_do(void)
{
	state_table[current_state]();
}

static void waitingFlanc(void)
{

	if(button_read()){
		*button = true;
		current_state = REBOUND_ZONE;
		timer_restart(&timer);
	}else{
		*button = false;
	}
}

static void reboundZone(void)
{
	unsigned int current_time = timer_getTime(&timer, MILLISECONDS);
	if(current_time < 50){
		*button = true;
	}else{
		*button = true;
		current_state = DIRECT_READ;
	}
}

static void directRead(void)
{
	*button = button_read();
	if(!*button){
		current_state = WAITING_FLANC;
	}
}
