cmake_minimum_required(VERSION 3.0)

project(mysql-connector-ace)

set(CMAKE_CXX_COMPILER "g++")

link_directories(/usr/lib/)

add_executable(test.cpp)

target_link_libraries(main mysqlcppconn mysqlcppconn8)
