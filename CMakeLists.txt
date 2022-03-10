cmake_minimum_required(VERSION 3.21)
project(TCP_IP)

set(CMAKE_CXX_STANDARD 17)

#add_executable(TCP_IP 第一章/1.1helloworld.cpp 第一章/low_open.cpp)

add_executable(test 第一章/fd_seri.cpp 第一章/fd_seri.cpp 第三章/inet_addr.cpp 第四章/echo_server.cpp 第四章/echo_client.cpp 第五章/op_client.cpp 第八章/gethostbyname.cpp 第十章/fork.cpp 第十章/wait.cpp 第十章/sigaction.cpp 第十章/echo_mpserv.cpp 第十一章/task.cpp 第十二章/select.cpp 第十二章/echo_selectserv.cpp)
