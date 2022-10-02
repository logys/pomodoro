
add_library(pomodoro STATIC 
	pomodoro.cpp 
	tickOneSecond.cpp 
	)

target_link_libraries(pomodoro PUBLIC
	blinking
	buzzing
	)

add_library(controller STATIC 
	controller.cpp
	circular_buffer.cpp
	)

add_library(blinking STATIC 
	services/blinking.cpp
	)

add_library(buzzing STATIC 
	services/buzzing.cpp
	)


if(CMAKE_SYSTEM_PROCESSOR STREQUAL "avr")
	target_compile_options(pomodoro PUBLIC 
		-mmcu=atmega328p
		-Os
		-Wall
		)
	target_include_directories(pomodoro PUBLIC ../STL)
	target_include_directories(controller PUBLIC ../STL)

	add_library(hal STATIC 
		hal/buzzer.c
		hal/powermode.c
		)
	target_compile_options(hal PUBLIC 
		-mmcu=atmega328p
		-Os
		-Wall
		)
	target_link_libraries(controller PUBLIC 
		hal
		pomodoro
		-mmcu=atmega328p
		)
endif()
