#include"pomodoro.h"
#include"handleLed.h"
#include"millis.h"
#include"buzzer.h"
#include"poweroff.h"
#include<stdbool.h>

static double pomodoro_progress_time = 0;
static double pomodoro_cummulated_time = 0;
static uint32_t last_millis = 0;
static short session_progress_time = 0;
enum time_type{PLAYING, REST};
static short actual_action = PLAYING;
struct {
}Pomodoro;
void pomodoro_init(void)
{
	sessions_reinitIndex();
	buzzer_open();
	handleLed_create();
	last_millis = millis();
	pomodoro_cummulated_time = 0;
	actual_action = PLAYING;
	poweroff();
}
static void computeSessionProgress(void)
{
	uint32_t current_millis = millis();
	pomodoro_cummulated_time += (current_millis - last_millis)/(60*1000.0);
	session_progress_time = pomodoro_cummulated_time*100/sessions_getSessionTime();
	last_millis = current_millis;
}
static bool sessionFinished(void)
{
	return session_progress_time >= 100;
}
static void reinitInternalTimes(void)
{
	session_progress_time = 0;
	pomodoro_cummulated_time = 0;
}
void pomodoro_update(void)
{
	computeSessionProgress();
	if(actual_action == PLAYING){
		handleLed_update(session_progress_time);
		if(sessionFinished()){
			buzzer_a(2, 400);
			reinitInternalTimes();
			actual_action = REST;
			//sessions_advanceSession();
		}
	}else if(actual_action == REST){
		handleLed_update(50);
		if(pomodoro_cummulated_time > 5){
			reinitInternalTimes();
			actual_action = PLAYING;
		}
	}
}
void pomodoro_destroy(void)
{
}
double pomodoro_getProgress(void)
{
	return pomodoro_progress_time;
}
#define USED_PINS 3
short pines[USED_PINS] = {0};
static bool isPinRegistred(short pin)
{
	for(short i = 0; i<USED_PINS; i++){
		if(pines[i] == pin)
			return true;
	}
	return false;
}
static bool isValidPin(short pin)
{
	if(pin < 2 || pin > 7 || pin == 4)
		return true;
	else
		return false;
}
bool pomodoro_setPin(PIN_TYPE pin_type, short pin)
{
	if(isPinRegistred(pin) || isValidPin(pin)){
		return false;
	}
	pines[pin_type] = pin;
	return true;
}
