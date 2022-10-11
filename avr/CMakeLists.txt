add_executable(Pomodoro main.cpp)

target_link_libraries(Pomodoro PUBLIC 
	pomodoro 
	hal
	-mmcu=atmega328p 
	)
target_compile_options(Pomodoro PUBLIC 
	-mmcu=atmega328p
	-Os
	-Wall
	)
target_include_directories(Pomodoro PUBLIC 
	../src
	../STL
	)

add_library(hal STATIC
	buzzer.c
	powermode.c
	)
target_compile_options(hal PUBLIC
	-mmcu=atmega328p
	-Os
	-Wall
	-DF_CPU=16000000UL
	)

target_include_directories(hal PUBLIC 
	../src/hal
	)

target_include_directories(pomodoro PUBLIC 
	../STL
	)
