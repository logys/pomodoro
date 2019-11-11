#include"pomodoro.h"
#include<math.h>

typedef struct Pomodoro{
	int8_t state;
	float sesiones[MAX_SESIONES + 1];
	double sesion_porcentaje;
	int8_t indice_sesion;
	int8_t button;
	double elapsed_time;
	bool play;
}Pomodoro;
static Pomodoro pomodoro ={	.state = UNKNOWN,
				.button = UNKNOWN,
				.indice_sesion = UNKNOWN,
				.sesion_porcentaje = UNKNOWN,
				.elapsed_time = UNKNOWN,
				.play = UNKNOWN
				};
static TIMER timer_pomodoro;
static void enablePomodoro(void);
static void disablePomodoro(void);
static void reinitPomodoro(void);

void initPomodoro(void)
{
	initTimer();
	initEventInput();
	initHandleLed();
	openBuzzer();

	timer_pomodoro = newTimer();
}
/* inicia el pomodoro con las sesiones indicada */
void nuevoSesion(float const sesiones[])
{
	short i;
	pomodoro.sesiones[0] = NAN;
	pomodoro.sesiones[MAX_SESIONES] = NAN;
	for(i = 0; !isnan(sesiones[i]) && (i < MAX_SESIONES); i++){
		pomodoro.sesiones[i] = sesiones[i];
		pomodoro.sesiones[i+1] = NAN;
	}
	pomodoro.indice_sesion = 0;
	setTimer(timer_pomodoro, pomodoro.sesiones[pomodoro.indice_sesion], MINUTES);
	enablePomodoro();
}

static void computePercent(void);
static void selectBuzzer(void);
static void sesionReached(void);
static void togglePomodoroPlay(void);
/* Comprueba el estado del pomodoro cada vez que se llama */
uint8_t actualizar(void)
{
	pomodoro.button = readEvent();
	pomodoro.elapsed_time = getTimer(timer_pomodoro, MINUTES);

	if(pomodoro.state == OFF ||
			(isnan(pomodoro.sesiones[pomodoro.indice_sesion])) ||
			pomodoro.button == POWEROFF){
		apagar();
		reinitPomodoro();
		return OFF;
	}else if(pomodoro.button == NONE){
		if(pomodoro.play == true){
			//computePlay();
			computePercent();
			if(pomodoro.sesion_porcentaje >= 100){
				selectBuzzer();
				sesionReached();
			}
		}else if(pomodoro.play == false)
			//computePause();
			writeToLed(50);
	}else if(pomodoro.button == PLAY_PAUSE){
		togglePomodoroPlay();
	}
	return ON;
}
static void togglePomodoroPlay(void)
{
	if(pomodoro.play){
		pomodoro.play = false;
		pauseTimer(timer_pomodoro);
	}
	else{
		pomodoro.play = true;
		resumeTimer(timer_pomodoro);
	}
}
static void sesionReached(void)
{
	pomodoro.indice_sesion++;
	setTimer(timer_pomodoro, 
	pomodoro.sesiones[pomodoro.indice_sesion], MINUTES);
	pomodoro.sesion_porcentaje = 0;
}
static void selectBuzzer(void)
{
			if(pomodoro.indice_sesion % 2 == 0)
				buzzer(2, 500);
			else
				buzzer(5, 100);
}
static void computePercent(void)
{
	pomodoro.sesion_porcentaje =
		(pomodoro.elapsed_time /
		pomodoro.sesiones[pomodoro.indice_sesion]) *
		100;
	writeToLed(pomodoro.sesion_porcentaje);
}

void enablePomodoro(void)
{
	pomodoro.state = ON;
	pomodoro.play = true;
}
void disablePomodoro(void)
{
	pomodoro.state = OFF;
}
void reinitPomodoro(void)
{
	/* Reinicia las sesiones */
	pomodoro.indice_sesion = 0;
	pomodoro.elapsed_time = 0;
	pomodoro.sesion_porcentaje = 0;
	reinitTimer(timer_pomodoro);
}

void pausa(void)
{
}

