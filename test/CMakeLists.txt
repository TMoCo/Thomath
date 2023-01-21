project("test-thomath" VERSION 1.0 DESCRIPTION "run library tests")

if(PROJECT_IS_TOP_LEVEL)
  message(STATUS "IS TOP LEVEL")
else()
  message(STATUS "IS NOT TOP LEVEL. TOP LEVEL IS: [${CMAKE_PROJECT_NAME}]")
endif()

# the rest will be taken care of by CMake
find_package(${CMAKE_PROJECT_NAME} CONFIG REQUIRED)

# it is an application
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        unit_tests.h
)

# linking to the library, here you need to provide the namespace too
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION "${CMAKE_SOURCE_DIR}/build")