set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR "avr")

set(CMAKE_C_COMPILER /usr/bin/avr-gcc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

add_custom_target(hex ALL avr-objcopy -O ihex apps/Pomodoro Pomodoro.hex DEPENDS Pomodoro)
#add_custom_target(flash ALL avrdude -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:Pomodoro.hex DEPENDS hex)
