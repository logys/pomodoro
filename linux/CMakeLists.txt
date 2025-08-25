set(CURSES_LIBRARY /usr/lib64/libncurses.so)
set(CURSES_INCLUDE_PATH /usr/include/ncurses)
find_package(Curses REQUIRED)

add_executable(${PROJECT_NAME}.elf 
	main.c
)

target_link_libraries(${PROJECT_NAME}.elf PUBLIC
	hal
	input
	pomodoro
	${CURSES_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}.elf PUBLIC 
	../src
	./
	${CURSES_INCLUDE_DIR}
)

add_library(hal STATIC
	led.c
	powermode.c
	buzzer.c
	button.c
)

target_include_directories(hal PUBLIC 
	${PROJECT_SOURCE_DIR}/src/hal
	./
)
