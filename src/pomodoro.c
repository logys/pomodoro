#include"pomodoro.h"
#include<stdint.h>
#include<math.h>
#include"log.h"
#include"led.h"
#include"buzzer.h"
#include"delay.h"

/* inicia el pomodoro con las sesiones indicada */
void nuevoSesion(struct pomodoro * const objeto, float const sesiones[])
{
	uint8_t i;
	for(i=0; !isnan(sesiones[i]) && (i < MAX_SESIONES - 1) ; i++){
		objeto->sesiones[i] = sesiones[i];
	}
	initTimer1Millis();
	objeto->sesiones[i+1] = NAN;
	objeto->sesion_porcentaje = 100;
	objeto->indice_sesion = 0;
	objeto->tiempo_actual = 0;
	objeto->tiempo_acumulado = 0;

}
/* cambia el estado del pomodoro cada vez que se llama */
uint8_t actualizar(struct pomodoro * const objeto)
{
	/* Si no hay sesiones, retorna 1 */
	if(isnan(objeto->sesiones[objeto->indice_sesion])){
		writeLed(0);
		return 1;
	}
	if(objeto->tiempo_actual == 0)
		objeto->tiempo_actual = millis();
	/* Si no se ha alcanzado el tiempo, continua acumulándolo */
	if(objeto->sesiones[objeto->indice_sesion] > objeto->tiempo_acumulado){
		/* diferencia de tiempo en porcentaje */
		objeto->sesion_porcentaje = (objeto->sesiones[objeto->indice_sesion] -
		objeto->tiempo_acumulado)*100/(objeto->sesiones[objeto->indice_sesion]*1.0);
		/* Salida al led */
		writeLed(objeto->sesion_porcentaje);
		/* Acumulación de tiempo */
		objeto->tiempo_acumulado += (millis() - objeto->tiempo_actual)/(double)(60000);
		objeto->tiempo_actual = millis();
		return 0;
	}else{
		/* Diferencia buzzer para sesión y descanso */
		if((int)objeto->sesiones[objeto->indice_sesion]%2 == 0)
			buzzer(2, 300);
		else
			buzzer(5, 100);
		objeto->indice_sesion += 1;
		objeto->tiempo_acumulado = 0;
		return 0;
	}
}

void reiniciar(struct pomodoro * const objeto)
{
	/* Reinicia las sesiones */
	objeto->indice_sesion = 0;
	objeto->tiempo_actual = 0;
	objeto->tiempo_acumulado = 0;
}

void pausa(struct pomodoro * const objeto)
{
	objeto->tiempo_actual = millis();
}
