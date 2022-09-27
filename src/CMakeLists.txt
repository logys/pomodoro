
add_library(pomodoro 
	STATIC 
	pomodoro.c
	)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "avr")
	add_library(bsp STATIC hal/bsp.cpp tickOneSecond.cpp)
	target_compile_options(pomodoro PUBLIC 
		-mmcu=atmega328p
		-Os
		)
	target_compile_options(bsp PUBLIC 
		-mmcu=atmega328p
		-Os
		)
	target_include_directories(pomodoro PUBLIC ../STL)
	target_include_directories(bsp PUBLIC ./ ../STL)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL x86_64)
	add_library(bsp STATIC 
		hal/button_posix.c
		hal/led_posix.c
		hal/buzzer_posix.c
		)
	target_include_directories(bsp PUBLIC hal)
	target_include_directories(pomodoro PUBLIC hal)
	target_compile_options(pomodoro PUBLIC 
		-Wall
		-Os
		-g
		)
endif()
