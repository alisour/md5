cmake_minimum_required(VERSION 3.0.0)
project(homework VERSION 0.1.0)

include(CTest)
enable_testing()


set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)


set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)


set(PROJECT_SOURCES
            ${PROJECT_SOURCE_DIR}/main.cpp
            ${PROJECT_SOURCE_DIR}/cipher.cpp
            )

set(PROJECT_HEADERS 
            ${PROJECT_INCLUDE_DIR}/cipher.hpp
            )
            
include_directories(${PROJECT_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
