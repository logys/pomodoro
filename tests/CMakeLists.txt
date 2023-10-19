add_executable(test_input test_input.cpp)
target_link_libraries(test_input gtest_main input)
add_test(NAME input COMMAND test_input)

target_include_directories(test_input PUBLIC ${PROJECT_SOURCE_DIR}/src/tasks)
target_include_directories(test_input PUBLIC ${PROJECT_SOURCE_DIR}/fff)

add_executable(test_pomodoro test_pomodoro.cpp)
target_link_libraries(test_pomodoro gtest_main pomodoro)
add_test(NAME pomodoro COMMAND test_pomodoro)

target_include_directories(test_pomodoro PUBLIC ${PROJECT_SOURCE_DIR}/src/tasks)
target_include_directories(test_pomodoro PUBLIC ${PROJECT_SOURCE_DIR}/fff)
