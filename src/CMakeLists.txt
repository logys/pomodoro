
add_library(pomodoro STATIC 
	tasks/pomodoro.c
	)

target_link_libraries(pomodoro PUBLIC
	)
target_include_directories(pomodoro PUBLIC .)

add_library(input STATIC 
	tasks/input.c
	)
target_link_libraries(input PUBLIC
	)
target_include_directories(input PUBLIC .)
