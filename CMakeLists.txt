cmake_minimum_required(VERSION 3.11)

project(Pomodoro LANGUAGES C CXX)

add_subdirectory(src)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "avr")
	add_subdirectory(avr)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "riscv")
	add_subdirectory(ch32v003)
else()
	add_subdirectory(googletest)
	enable_testing()
	add_subdirectory(tests)
endif()
