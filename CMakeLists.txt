cmake_minimum_required(VERSION 3.5)

project(Pomodoro LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
	add_subdirectory(googletest)
	enable_testing()
	add_subdirectory(tests)
endif()
