#BOARD_TAG = uno
#BOARDS_TXT = $(ARDUINO_DIR)/boards.txt
#include $(ARDMK_DIR)/Arduino.mk
#CFLAGS=-DATTINY
objects=led.o millis.o buzzer.o pomodoro.o push_driver.o timer.o event_input.o handleLed.o pomodoro_sessions.o 
mmcu=attiny85
CFLAGS=-Wall -O2 -mmcu=${mmcu} --std=gnu11 -lm -DATTINY
programer=arduino
mcu=t85
puerto=/dev/ttyACM0
CC=avr-gcc

all:main.ihx $(objects)

main.ihx: main.elf
	avr-objcopy -O ihex main.elf main.ihx
	avr-size --mcu=${mmcu} -C --format=avr main.elf

main.elf: main.c $(objects) *.h
	avr-gcc ${CFLAGS} -o main.elf $(objects) main.c

../bin/%.o: ./%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm ${objects} main.ihx main.elf

flash: main.ihx
	avrdude -c ${programer} -p ${mcu} -P ${puerto} -b 19200 -U flash:w:main.ihx
