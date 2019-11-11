#include "unity.h"
#include "buzzer.h"
#include "stub_io.h"
#include "mock_timer.h"

void setUp(void)
{
	openBuzzer();
}

void tearDown(void)
{
	closeBuzzer();
}

uint8_t buzzerBit = (1<<PB1);
uint8_t buzzerBitOn = (1<<PB1);
uint8_t buzzerBitOff = ~(1<<PB1);
void test_open_off(void)
{
	DDRB = 0x0;
	PORTB = 0xFF;
	openBuzzer();
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOn, DDRB);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, PORTB);
}

void test_close(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	closeBuzzer();
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, DDRB);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, PORTB);
}

void test_buzzer_on(void)
{
	writeBuzz(ON);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOn, PORTB);
}

void test_buzzer_off(void)
{
	writeBuzz(ON);
	writeBuzz(OFF);
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOff, PORTB);

}

void test_read_buzzer(void)
{
	TEST_ASSERT_EQUAL(OFF, readBuzz());
	PINB = 0xff;
	TEST_ASSERT_EQUAL(ON, readBuzz());
}

void test_toggle_buzzer(void)
{
	toggle();
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOn, PINB);
	toggle();
	TEST_ASSERT_BITS(buzzerBit, buzzerBitOn, PINB);
}

void test_buzzer_number_of_ticks(void)
{
	int delay_time_ms = 500;
	int ticks_number = 10;

	for(int i = 0; i< ticks_number; i++){
		delay_Expect(delay_time_ms);
		delay_Expect(delay_time_ms);
	}
	buzzer(ticks_number, delay_time_ms);
}

void test_buzzer_diferent_delays(void)
{
	int delay_time_ms = 100;
	int ticks_number = 1;

	delay_Expect(delay_time_ms);
	delay_Expect(delay_time_ms);

	buzzer(ticks_number, delay_time_ms);
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

	buzzer(ticks_number, delay_time_ms);
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

	buzzer(ticks_number, delay_time_ms);
}

void test_minimun_values_greather_than_0(void)
{
	int delay_time_ms = -1;
	int ticks_number = -1;

	buzzer(ticks_number, delay_time_ms);
}
