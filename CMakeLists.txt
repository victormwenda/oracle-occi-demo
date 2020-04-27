cmake_minimum_required(VERSION 3.16)
project(oracle_occi_demo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER /usr/bin/g++-4.8)

set(INSTANTCLIENT /opt/oracle/instant-client/instantclient_11_1)

set(OCCI_LIBS

        ${INSTANTCLIENT}/libclntsh.so.11.1
        ${INSTANTCLIENT}/libocci.so.11.1
        ${INSTANTCLIENT}/libociei.so
        ${INSTANTCLIENT}/libnnz11.so
        )

set(ORACLE_HEADERS includes/instantclient_11_1/sdk/include)

include_directories(${ORACLE_HEADERS})

add_executable(oracle_occi_demo main.cpp)

target_link_libraries(oracle_occi_demo ${OCCI_LIBS})