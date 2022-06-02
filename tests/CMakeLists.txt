add_executable(test_pomodoro test_pomodoro.cpp)
target_include_directories(test_pomodoro PUBLIC ../src)
target_link_libraries(test_pomodoro gtest_main 	pomodoro)
add_test(NAME pomodoro COMMAND test_pomodoro)
