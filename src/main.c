/**
 * \file 
 * \brief main de este proyecto
 * \mainpage Description
 * Programa simple que implementa un pomodoro para sesiones de estudio. El
 * dispositivo cuenta con un buzzer que indica el termino e inicio de una 
 * sesión, un led que muestra el progreso del tiempo de sesión y un par de 
 * botones para controlarlo.
 *
 * \author Logy
 * \version 3.0 
 * \bug no por ahora
 * \warning sin pruebas
 * */

#include"main.h"
#include"pomodoro.h"
#ifdef TEST
	#define LOOP
#else
	#define LOOP while(1)
int main(void)
{
	return appMain();	
}
#endif

int appMain(void)
{
	initPomodoro();
	setSesiones(20,8,20,8,20);
	LOOP{
		actualizar();
		updateLed();
	}
	return 1;
}
