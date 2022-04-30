include_directories(./)

add_library(pomodoro pomodoro.cpp)
add_library(tickOneSecond tickOneSecond.cpp)

add_executable(Pomodoro main.cpp bsp.cpp)
target_link_libraries(Pomodoro pomodoro tickOneSecond)
