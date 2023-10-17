add_library(pomodoro STATIC 
	tasks/pomodoro.c
	)

target_link_libraries(pomodoro PUBLIC
	hal
	)
target_include_directories(pomodoro PUBLIC 
	./hal
)

add_library(input STATIC 
	tasks/input.c
	)
target_link_libraries(input PUBLIC
	pomodoro
	)
target_include_directories(input PUBLIC 
	./hal
)
