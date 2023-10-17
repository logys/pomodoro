add_executable(${PROJECT_NAME}.elf main.c)

target_link_libraries(${PROJECT_NAME}.elf PUBLIC 
	pomodoro 
	input
	hal
	)
target_include_directories(${PROJECT_NAME}.elf PUBLIC 
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
	-DF_CPU=128000UL
	)

target_include_directories(hal PUBLIC 
	../src/hal
	)

add_custom_target(hex ALL
	COMMAND avr-objcopy -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(size ALL
	COMMAND avr-size ${PROJECT_NAME}.elf -G
	DEPENDS ${PROJECT_NAME}.elf)
