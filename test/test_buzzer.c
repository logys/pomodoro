#include "unity.h"
#include "buzzer.h"
#include "stub_io.h"
#include "mock_timer.h"

void setUp(void)
{
	DDRB = 0x0;
	PORTB = 0xFF;
	buzzer_open();
}

void tearDown(void)
{
	buzzer_close();
}

uint8_t buzzerBit = (1<<PB1);
uint8_t buzzerBitOn = (1<<PB1);
uint8_t buzzerBitOff = ~(1<<PB1);
void test_open_off(void)
{
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOn, DDRB);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, PORTB);
}
void test_close(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	buzzer_close();
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, DDRB);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, PORTB);
}

void test_buzzer_on(void)
{
	buzzer_write(BUZZER_ON);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOn, PORTB);
}

void test_buzzer_off(void)
{
	buzzer_write(BUZZER_ON);
	buzzer_write(BUZZER_OFF);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, PORTB);

}

void test_buzzer_number_of_ticks(void)
{
	int delay_time_ms = 500;
	int ticks_number = 10;

	for(int i = 0; i< ticks_number; i++){
		delay_Expect(delay_time_ms);
		delay_Expect(delay_time_ms);
	}
	buzzer_a(ticks_number, delay_time_ms);
}

void test_buzzer_diferent_delays(void)
{
	int delay_time_ms = 100;
	int ticks_number = 1;

	delay_Expect(delay_time_ms);
	delay_Expect(delay_time_ms);

	buzzer_a(ticks_number, delay_time_ms);
}

void test_max_ticks_equal_10(void)
{
	int delay_time_ms = 100;
	int ticks_number = 20;
	int max_ticks_number = 10;

	for(int i = 0; i< max_ticks_number; i++){
		delay_Expect(delay_time_ms);
		delay_Expect(delay_time_ms);
	}

	buzzer_a(ticks_number, delay_time_ms);
}

void test_max_time_equal_1000ms(void)
{
	int delay_time_ms = 5000;
	int ticks_number = 10;
	int max_time_ms = 1000;

	for(int i = 0; i< ticks_number; i++){
		delay_Expect(max_time_ms);
		delay_Expect(max_time_ms);
	}

	buzzer_a(ticks_number, delay_time_ms);
}

void test_minimun_values_greather_than_0(void)
{
	int delay_time_ms = -1;
	int ticks_number = -1;

	buzzer_a(ticks_number, delay_time_ms);
}
