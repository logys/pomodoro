add_executable(Pomodoro main.c)

target_link_libraries(Pomodoro PUBLIC 
	pomodoro 
	input
	hal
	-mmcu=attiny85 
	)
target_compile_options(Pomodoro PUBLIC 
	-mmcu=attiny85 
	-Os
	-Wall
	)
target_include_directories(Pomodoro PUBLIC 
	../src
	)

add_library(hal STATIC
	buzzer.c
	powermode.c
	button.c
	led.c
	tick.c
	)
target_compile_options(hal PUBLIC
	-mmcu=attiny85 
	-Os
	-Wall
	-DF_CPU=1000000UL
	)
target_compile_options(pomodoro PUBLIC
	-mmcu=attiny85 
	-Os
	-Wall
	)
target_compile_options(input PUBLIC
	-mmcu=attiny85 
	-Os
	-Wall
	)

target_include_directories(hal PUBLIC 
	../src/hal
	)
