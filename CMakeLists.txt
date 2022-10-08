cmake_minimum_required(VERSION 3.11)

project(Pomodoro LANGUAGES C CXX)

add_subdirectory(src)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "avr")
	add_subdirectory(avr)
	include_directories(./STL)
else()
	add_subdirectory(googletest)
	enable_testing()
	add_subdirectory(tests)
endif()
