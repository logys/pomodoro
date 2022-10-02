if(CMAKE_SYSTEM_NAME STREQUAL Generic)
	add_executable(Pomodoro main.cpp bsp.cpp)
	target_link_libraries(Pomodoro PUBLIC 
		blinking
		buzzing
		pomodoro 
		controller 
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
endif()
