cmake_minimum_required(VERSION 3.21)
project(TCP_IP)

set(CMAKE_CXX_STANDARD 17)

#add_executable(TCP_IP 第一章/1.1helloworld.cpp 第一章/low_open.cpp)

add_executable(test 第一章/fd_seri.cpp 第一章/fd_seri.cpp 第三章/inet_addr.cpp 第四章/echo_server.cpp 第四章/echo_client.cpp)
