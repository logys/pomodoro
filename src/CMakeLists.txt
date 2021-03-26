add_avr_library(
	firmware
	led.c
	led.h
	button.c
	button.h
	buzzer.c
	buzzer.h
	poweroff.c
	poweroff.h
	millis.c
	millis.h
)

add_avr_executable(
	main
	main.c
	main.h
)

find_library(C_LIB c)
message(STATUS "avr-libc: ${C_LIB}")

avr_target_link_libraries(main firmware ${C_LIB})
