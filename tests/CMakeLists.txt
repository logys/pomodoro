
include_directories(../src)

add_executable(test_pomodoro test_pomodoro.cpp)
target_link_libraries(test_pomodoro gtest_main pomodoro tickOneSecond controller)
add_test(NAME pomodoro COMMAND test_pomodoro)
