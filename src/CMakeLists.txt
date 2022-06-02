
add_library(pomodoro 
	STATIC 
	pomodoro.cpp 
	pomodoro.hpp
	tickOneSecond.cpp 
	controller.cpp
	circular_buffer.cpp
	pomodoro.hpp
	)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "avr")
	target_compile_options(pomodoro PUBLIC 
		-mmcu=atmega328p
		-Os
		)
	target_include_directories(pomodoro PUBLIC ../STL)
endif()
