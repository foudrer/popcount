PROJECT(POPCOUNT)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(SOURCES
        src/popcount.cpp)
add_library(popcount SHARED ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mpopcnt")
target_link_libraries(popcount)

add_library(popcount_static STATIC ${SOURCES})
SET_TARGET_PROPERTIES(popcount_static PROPERTIES OUTPUT_NAME "popcount")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mpopcnt")
target_link_libraries(popcount)

#Benchmark

set(BENCHMARK
        benchmark/bench.cpp)
add_executable(bench ${BENCHMARK})
target_link_libraries(bench popcount)
