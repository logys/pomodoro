include_directories(./)

add_library(pomodoro pomodoro.cpp)
add_library(tickOneSecond tickOneSecond.cpp)
add_library(controller controller.cpp)
add_library(circular_buffer circular_buffer.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL Generic)
	include_directories(../STL)
	add_executable(Pomodoro main.cpp bsp.cpp)
	target_link_libraries(Pomodoro 
		controller
		pomodoro 
		tickOneSecond 
		circular_buffer
		)
endif()
