cmake_minimum_required(VERSION 2.6)

project(echo CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "debug")
endif()

set (MUDUO_PATH "${CMAKE_SOURCE_DIR}/third-party-libs/muduo")
set (CURL_PATH "${CMAKE_SOURCE_DIR}/third-party-libs/curl")
set(THIRD_LIBS_PATH "${CMAKE_SOURCE_DIR}/third-party-libs")
add_definitions(-std=c++11)

set(CXX_FLAGS
 -g
 # -DVALGRIND
 # -DMUDUO_STD_STRING
 -Wall
 -Wextra
 # -m32
 #-Werror
 #-Wconversion
 -Wno-unused-parameter
 #-Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 # -std=c++0x
 -rdynamic
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_path(Muduo_INCLUDE_DIR muduo "${MUDUO_PATH}/include")
find_path(Muduo_LIBRARY_DIR libmuduo_net.a "${MUDUO_PATH}/lib")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${Muduo_LIBRARY_DIR})
message(STATUS ${Muduo_INCLUDE_DIR})
message(STATUS ${Muduo_LIBRARY_DIR})

include_directories(${Muduo_INCLUDE_DIR})
find_library(muduo_base muduo_base)
find_library(muduo_net muduo_net)
message(STATUS ${muduo_base})
message(STATUS ${muduo_net})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories (${CURL_PATH}/include)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${THIRD_LIBS_PATH}/rapidJson/include)
include_directories(${THIRD_LIBS_PATH}/hiredis/include)
include_directories(${THIRD_LIBS_PATH}/protobuf/include)
include_directories(${CMAKE_SOURCE_DIR}/src/publicUtil)
include_directories(${CMAKE_SOURCE_DIR}/src/autoReservate)

link_directories(${CURL_PATH}/lib ${THIRD_LIBS_PATH}/hiredis/lib ${THIRD_LIBS_PATH}/protobuf/lib)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/autoReservate SRCS_AUTORESERVATE)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/publicUtil SRCS_PUBLICUTIL)

add_executable(autoReservate ${SRCS_AUTORESERVATE} ${SRCS_PUBLICUTIL}) 

target_link_libraries(autoReservate ${muduo_net} ${muduo_base} curl pthread rt hiredis protobuf)



