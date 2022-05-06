include_directories(./)

add_library(pomodoro pomodoro.cpp)
add_library(tickOneSecond tickOneSecond.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL Generic)
	add_executable(Pomodoro main.cpp bsp.cpp)
	target_link_libraries(Pomodoro pomodoro tickOneSecond)
endif()
