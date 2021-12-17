cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")

set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} ${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_BUILD_TYPE RelWithDebInfo)

project(LockTransfers)
find_package (Threads REQUIRED)

include_directories(lock_transfers/include)
find_program(iwyu_path NAMES include-what-you-use iwyu REQUIRED)
message(${iwyu_path})
# If using CGAL<3.18, you remove REQUIRED and use
if(NOT iwyu_path)
message(FATAL_ERROR "Could not find the program include-what-you-use")
endif()


add_executable(LockTransfers lock_transfers/main.cpp lock_transfers/account.cpp lock_transfers/bank.cpp)

target_link_libraries(LockTransfers
${CMAKE_THREAD_LIBS_INIT} 
)

set(iwyu_path_and_options
    ${iwyu_path}
    -Xiwyu
    --cxx17ns)

set_property(TARGET LockTransfers
    PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path_and_options})