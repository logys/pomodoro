
include_directories(../src)

add_executable(test_pomodoro test_pomodoro.cpp)
target_link_libraries(test_pomodoro gtest_main 	pomodoro tickOneSecond)
add_test(NAME pomodoro COMMAND test_pomodoro)

add_executable(test_buzzer test_buzzer.cpp)
target_link_libraries(test_buzzer gtest_main buzzer)
add_test(NAME buzzer COMMAND test_buzzer)
