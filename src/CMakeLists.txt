include_directories(./)

add_library(pomodoro pomodoro.cpp)
add_library(buzzer buzzer.cpp)
add_library(tickOneSecond tickOneSecond.cpp)
add_library(button button.cpp)

add_executable(Pomodoro main.cpp)
target_link_libraries(Pomodoro buzzer tickOneSecond button)
