#include "unity.h"
#include "handleLed.h"
#include "mock_timer.h"
#include "mock_led.h"
#include <stdbool.h>

void setUp(void)
{
	initTimer_Ignore();
	openLed_Ignore();
	newTimer_ExpectAndReturn(NULL);
	initHandleLed();
}

void tearDown(void)
{
}

void setWorkCicle(double work_cicle);
void test_set_sesion(void)
{
	setWorkCicle(0);
}
void setWorkCicle(double work_cicle)
{
	if(work_cicle > 100)
		work_cicle = 100;
	else if(work_cicle < 0)
		work_cicle = 0;
	double time_toggle = -492/100.0*work_cicle + 500;
	setTimer_Expect(NULL, time_toggle, MILLISECONDS);
	writeToLed(work_cicle);
}

void assertToggleOnWorkCicle(uint32_t time_to_toggle);
void test_toggle_after_500ms_on_0_wc(void)
{
	double work_cicle = 0;
	setWorkCicle(work_cicle);

	double time_toggle = 500;
	assertToggleOnWorkCicle(time_toggle);
}
void assertToggleOnWorkCicle(uint32_t time_to_toggle)
{
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, time_to_toggle);
	toggleLed_Expect();
	updateLed();
}
void test_toggle_after_8ms_on_100_wc(void)
{
	double work_cicle = 100;
	setWorkCicle(work_cicle);

	double time_toggle = 8;
	assertToggleOnWorkCicle(time_toggle);
}

void test_toggle_two_times_after_one_cicle(void)
{
	double work_cicle = 100;
	setWorkCicle(work_cicle);

	double time_toggle = 500;
	for(int i = 0; i<2; i++)
		assertToggleOnWorkCicle(time_toggle);
}

void test_only_set_one_time_on_each_cicle(void)
{
	int work_cicle = 0;
	setWorkCicle(work_cicle);
	int pretend_rewrite_work_cicle = 10;
	writeToLed(pretend_rewrite_work_cicle);

	int time_correspond_to_first_work_cicle = 500;
	assertToggleOnWorkCicle(time_correspond_to_first_work_cicle);
}

void test_on_finish_cicle_enable_rewrite_cile(void)
{
	int primer_ciclo = 0;
	setWorkCicle(primer_ciclo);
	int expect_time = 500;
	assertToggleOnWorkCicle(expect_time);
	assertToggleOnWorkCicle(expect_time);

	int second_cicle = 100;
	setWorkCicle(100);
	int second_time = 8;
	assertToggleOnWorkCicle(second_time);
	assertToggleOnWorkCicle(second_time);
}

void test_write_out_boundaries(void)
{

	setWorkCicle(1000);

	assertToggleOnWorkCicle(500);
}
