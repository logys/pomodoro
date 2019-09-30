/*
 * =====================================================================================
 *
 *       Filename:  spy_delay.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/09/19 10:45:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Luis Antonio Sánchez Monterde (logy), antonio.dgr.ink@gmail.com
 *   Organization:  eleckia
 *
 * =====================================================================================
 */

#include "spy_delay.h"

static uint32_t tiempo = 0;
uint32_t millis(void)
{
	return tiempo;
}

void fake_setMillis(uint32_t fake_time)
{
	tiempo = fake_time;
}

void initTimer1Millis(void){
	return ;
}

void reiniciarMillis(void)
{
	fake_setMillis(0);
}
