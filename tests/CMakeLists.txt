add_executable(test_pomodoro test_pomodoro.cpp 
	../src/pomodoro.cpp
	../src/tasks/rebound.cpp)
target_include_directories(test_pomodoro PUBLIC ../src)
target_link_libraries(test_pomodoro PUBLIC gtest_main)
add_test(NAME pomodoro COMMAND test_pomodoro)
