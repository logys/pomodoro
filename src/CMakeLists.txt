include_directories(./)

set(Sources
	)

add_library(pomodoro 
	pomodoro.cpp
	tickOneSecond.cpp
	button.cpp
	)
add_library(buzzer buzzer.cpp)
add_library(tickOneSecond tickOneSecond.cpp)
