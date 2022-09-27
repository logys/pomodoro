if(CMAKE_SYSTEM_PROCESSOR STREQUAL avr)
	add_executable(Pomodoro main.cpp)
	target_link_libraries(Pomodoro PUBLIC 
		pomodoro 
		bsp
		-mmcu=atmega328p 
		)
	target_compile_options(Pomodoro PUBLIC 
		-mmcu=atmega328p
		-Os
		)
	target_include_directories(Pomodoro PUBLIC 
		../src
		../src/hal/
		../STL
		)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL x86_64)
	add_executable(Pomodoro main.c)
	target_link_libraries(Pomodoro PUBLIC 
		bsp
		pomodoro 
		)
	target_include_directories(Pomodoro PUBLIC 
		../src/hal
		../src
		)
	target_compile_options(Pomodoro PUBLIC 
		-Wall
		-Os
		)
endif()
