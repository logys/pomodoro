#BOARD_TAG = uno
#BOARDS_TXT = $(ARDUINO_DIR)/boards.txt
#include $(ARDMK_DIR)/Arduino.mk
#CFLAGS=-DATTINY
objects=*.o
mmcu=attiny85
CFLAGS=-Wall -mmcu=${mmcu} --std=gnu11 -lm -DATTINY
programer=arduino
mcu=t85
puerto=/dev/ttyACM0
CC=avr-gcc

all:main.ihx

main.ihx: main.elf
	avr-objcopy -O ihex main.elf main.ihx
	avr-size --mcu=${mmcu} -C --format=avr main.elf

main.elf: main.c
	avr-gcc -mmcu=attiny85 *.c -o main.elf

clean:
	rm ${objects} main.ihx main.elf

flash: main.ihx
	avrdude -c ${programer} -p ${mcu} -P ${puerto} -b 19200 -U flash:w:main.ihx
