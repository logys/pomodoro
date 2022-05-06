set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR "avr")

set(CMAKE_C_COMPILER /usr/bin/avr-gcc)
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega328p -lm -Wl,--gc-sections -Wl,-Map,out.map")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

add_compile_options(-Wall -mmcu=atmega328p -Os)
add_custom_target(hex ALL avr-objcopy -O ihex src/Pomodoro Pomodoro.hex DEPENDS Pomodoro)
