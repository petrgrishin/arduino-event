cmake_minimum_required(VERSION 2.8)

project(tests-arduino-listener)

set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/ListenerTest.cpp
)

add_executable(tests-arduino-listener ${SOURCE_FILES})

enable_testing()

add_test(NAME Tests COMMAND tests-arduino-listener)
