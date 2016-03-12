project(ChapterFirstExample)

cmake_minimum_required(VERSION 2.8)

if (DEFINED ENV{GTEST_HOME})
  set(GTEST_HOME $ENV{GTEST_HOME})
else()
  set(GTEST_HOME "/Users/max/Documents/playground/cpp/googletest-master")
endif()

MESSAGE( "GTEST_HOME: " ${GTEST_HOME})

include_directories("${GTEST_HOME}/googletest/include")
include_directories("${GTEST_HOME}/googlemock/include")

link_directories("${GTEST_HOME}/build/googlemock/gtest")
link_directories("${GTEST_HOME}/build/googlemock")

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(sources SoundexTest.cc)

add_executable(SoundexTest ${sources})

target_link_libraries(SoundexTest pthread)
target_link_libraries(SoundexTest gmock)
target_link_libraries(SoundexTest gtest)
