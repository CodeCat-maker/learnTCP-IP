cmake_minimum_required(VERSION 3.21)
project(TCP_IP)

set(CMAKE_CXX_STANDARD 17)

#add_executable(TCP_IP 第一章/1.1helloworld.cpp 第一章/low_open.cpp)

add_executable(test TCP_IP_C语言/第一章/fd_seri.cpp TCP_IP_C语言/第一章/fd_seri.cpp TCP_IP_C语言/第三章/inet_addr.cpp TCP_IP_C语言/第四章/echo_server.cpp TCP_IP_C语言/第四章/echo_client.cpp TCP_IP_C语言/第五章/op_client.cpp TCP_IP_C语言/第八章/gethostbyname.cpp TCP_IP_C语言/第十章/fork.cpp TCP_IP_C语言/第十章/wait.cpp TCP_IP_C语言/第十章/sigaction.cpp TCP_IP_C语言/第十章/echo_mpserv.cpp TCP_IP_C语言/第十一章/task.cpp TCP_IP_C语言/第十二章/select.cpp TCP_IP_C语言/第十二章/echo_selectserv.cpp 30dayMakeCppServer/day02/server.cpp 30dayMakeCppServer/day02/util.h)
