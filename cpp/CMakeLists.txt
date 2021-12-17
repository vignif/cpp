cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")

set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} ${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_BUILD_TYPE RelWithDebInfo)

project(LockTransfers)
find_package (Threads REQUIRED)

include_directories(lock_transfers/include)

add_executable(LockTransfers lock_transfers/main.cpp lock_transfers/account.cpp lock_transfers/bank.cpp)

target_link_libraries(LockTransfers
    ${CMAKE_THREAD_LIBS_INIT} 
)
