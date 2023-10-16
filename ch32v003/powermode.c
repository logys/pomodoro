#define SYSTEM_CORE_CLOCK 48000000UL
#define APB_CLOCK SYSTEM_CORE_CLOCK
#include "powermode.h"
#include "ch32v003fun.h"

static void setWakeUp(void);
static void enableAutoWakeup(void);
static void disableAutoWakeup(void);
static void setExternalInterruptWakeup(void);

void powermode_init(void)
{
	// enable power interface module clock
	RCC->APB1PCENR |= RCC_APB1Periph_PWR;

	// enable low speed oscillator (LSI)
	RCC->RSTSCKR |= RCC_LSION;
	while ((RCC->RSTSCKR & RCC_LSIRDY) == 0) {}

	setWakeUp();
	setExternalInterruptWakeup();
}

static void setExternalInterruptWakeup(void)
{
}

static void setWakeUp(void)
{
	// enable AutoWakeUp event
	EXTI->EVENR |= EXTI_Line9;
	EXTI->FTENR |= EXTI_Line9;

	// configure AWU prescaler
	PWR->AWUPSC |= PWR_AWU_Prescaler_32;

	// configure AWU window comparison value
	PWR->AWUWR &= ~0x3f;
	PWR->AWUWR |= 37;

	enableAutoWakeup();

	PFIC->SCTLR |= (1 << 2);
}

static void enableAutoWakeup(void)
{
	// enable AWU
	PWR->AWUCSR |= (1 << 1);
}

void powermode_standBy(void)
{
	disableAutoWakeup();
	PWR->CTLR |= PWR_CTLR_PDDS;
	__WFE();
	enableAutoWakeup();
}

static void disableAutoWakeup(void)
{
	// disable AWU
	PWR->AWUCSR &= ~(1 << 1);
}

void powermode_sleep(void)
{
	// select standby on power-down
	__WFE();
}
