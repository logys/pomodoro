add_executable(${PROJECT_NAME}.elf 
	main.c
)

target_link_libraries(${PROJECT_NAME}.elf PUBLIC
	hal
	input
	pomodoro
)

target_include_directories(${PROJECT_NAME}.elf PUBLIC 
	../src
	./
)

add_library(hal STATIC
        ../ch32v003fun/ch32fun/ch32fun.c
	led.c
	powermode.c
	buzzer.c
	button.c
)

target_include_directories(hal PUBLIC 
	${PROJECT_SOURCE_DIR}/src/hal
        ../ch32v003fun/ch32fun
	./
)
add_custom_target(size ALL
	COMMAND /home/antonio/Builds/riscv/bin/riscv64-unknown-elf-size
       	${PROJECT_NAME}.elf -G
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(bin ALL
	COMMAND /home/antonio/Builds/riscv/bin/riscv64-unknown-elf-objcopy -O binary
       	${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
	DEPENDS ${PROJECT_NAME}.elf)
