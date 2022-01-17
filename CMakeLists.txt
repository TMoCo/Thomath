cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

project(Thomath
  VERSION 1.0
  LANGUAGES CXX C)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# source
file(GLOB_RECURSE SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/*.c
  ${CMAKE_SOURCE_DIR}/*.cpp)

# include
file(GLOB_RECURSE HEADER_FILES
  ${CMAKE_SOURCE_DIR}/*.h
  ${CMAKE_SOURCE_DIR}/*.hpp)

include_directories(${CMAKE_SOURCE_DIR})

# create executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

if(MSVC_IDE)
  # set start up project
  if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.8.0")
    set(VS_STARTUP_PROJECT ${PROJECT_NAME})
  endif()
endif()