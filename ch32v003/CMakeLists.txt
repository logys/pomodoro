add_executable(${PROJECT_NAME}.elf 
	main.c
)

target_link_libraries(${PROJECT_NAME}.elf PUBLIC
	hal
)

target_include_directories(${PROJECT_NAME}.elf PUBLIC 
	#../src
	./
)

add_library(hal STATIC
        ch32v003fun.c
	led.c
	powermode.c
	buzzer.c
)

target_include_directories(hal PUBLIC 
	./
)
add_custom_target(size ALL
	COMMAND /home/antonio/Builds/riscv32-unknown-elf.gcc-10.1.0.rv32e.ilp32e.newlib/bin/riscv32-unknown-elf-size
       	${PROJECT_NAME}.elf -G
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(bin ALL
	COMMAND /home/antonio/Builds/riscv/bin/riscv32-unknown-elf-objcopy -O binary
       	${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
	DEPENDS ${PROJECT_NAME}.elf)
