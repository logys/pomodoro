add_executable(${PROJECT_NAME}.elf main.c ch32v003fun.c)

target_include_directories(${PROJECT_NAME}.elf PUBLIC 
	#../src
	./
)

#target_link_libraries(${PROJECT_NAME}.elf PUBLIC 
	#pomodoro 
	#	input
	#hal
	#)

	#add_library(hal STATIC
	#buzzer.c
	#powermode.c
	#button.c
	#led.c
	#tick.c
	#./ch32v003fun.c
	#)

	#target_compile_options(hal PUBLIC
	#-DF_CPU=128000UL
	#)

	#target_include_directories(hal PUBLIC 
	#../src/hal
	#./
	#)

	#add_custom_target(hex ALL
	#COMMAND avr-objcopy -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
	#DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(size ALL
	COMMAND /home/antonio/Builds/riscv32-unknown-elf.gcc-10.1.0.rv32e.ilp32e.newlib/bin/riscv32-unknown-elf-size
       	${PROJECT_NAME}.elf -G
	DEPENDS ${PROJECT_NAME}.elf)
