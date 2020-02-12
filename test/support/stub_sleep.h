/*
 * =====================================================================================
 *
 *       Filename:  stub_sleep.h
 *
 *    Description:  stub for sleep
 *
 *        Version:  1.0
 *        Created:  09/02/20 00:39:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Luis Antonio Sánchez Monterde (logy), antonio.dgr.ink@gmail.com
 *   Organization:  eleckia
 *
 * =====================================================================================
 */
#ifndef STUB_SLEEP
#define STUB_SLEEP
enum MODE_SLEEP{SLEEP_MODE_PWR_DOWN};
void set_sleep_mode(enum MODE_SLEEP);
void sleep_enable(void);
void sleep_disable(void);
void sleep_cpu(void);
void sleep_mode(void);
void sleep_bod_disable(void);
#endif
