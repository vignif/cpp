cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")

set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} ${CMAKE_CXX_FLAGS} -pthread -fsanitize=address")

project(Pool)
find_package (Threads REQUIRED)

include_directories(include)

add_executable(Pool src/main.cpp src/account.cpp src/bank.cpp)

target_link_libraries(Pool
    ${CMAKE_THREAD_LIBS_INIT} -fsanitize=address
)
