cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

###########
# PROJECT #
###########

project(Thomath VERSION 1.0 LANGUAGES CXX C)

if(PROJECT_IS_TOP_LEVEL)
  message(STATUS "IS TOP LEVEL")
else()
  message(STATUS "IS NOT TOP LEVEL. TOP LEVEL IS: [${CMAKE_PROJECT_NAME}]")
endif()

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


###############
# THE LIBRARY #
###############

add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME} 
  PRIVATE
    src/Matrix4.cpp
    src/Quaternion.cpp
    src/Vector2.cpp
    src/Vector3.cpp
    src/Vector4.cpp
    include/Matrix4.hpp
    include/Quaternion.hpp
    include/Vector2.hpp
    include/Vector3.hpp
    include/Vector4.hpp
    include/constants.hpp
    include/routines.hpp
    include/sse2neon.h
    include/thomath.hpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX is not set\n"
        "Default value: ${CMAKE_INSTALL_PREFIX}\n"
        "Will set it to ${CMAKE_SOURCE_DIR}/build"
    )
    set(CMAKE_INSTALL_PREFIX
        "${CMAKE_SOURCE_DIR}/build"
        CACHE PATH "Where the library will be installed to" FORCE
    )
else()
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX was already set\n"
        "Current value: ${CMAKE_INSTALL_PREFIX}"
    )
endif()

# Public headers property
set(public_headers
include/Matrix4.hpp
include/Quaternion.hpp
include/Vector2.hpp
include/Vector3.hpp
include/Vector4.hpp
include/constants.hpp
include/routines.hpp
include/sse2neon.h
include/thomath.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

include(GNUInstallDirs)
foreach(header ${public_headers})
    file(RELATIVE_PATH header_file_path "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}" "${CMAKE_CURRENT_SOURCE_DIR}/${header}")
    get_filename_component(header_directory_path "${header_file_path}" DIRECTORY)
    install(
        FILES ${header}
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${header_directory_path}/${PROJECT_NAME}"
    )
endforeach()
    
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

###########
# INSTALL #
###########

install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}Targets"
    # these get default values from GNUInstallDirs, no need to set them
    #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # bin
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    #ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    # except for public headers, as we want them to be inside a library folder
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME} # include/SomeLibrary
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} # include
)

# generate and install export file
install(EXPORT "${PROJECT_NAME}Targets"
    FILE "${PROJECT_NAME}Targets.cmake"
    DESTINATION cmake
)

include(CMakePackageConfigHelpers)

# generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION "${version}"
    COMPATIBILITY AnyNewerVersion
)
# create config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION cmake
)
# install config files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION cmake
)
# generate the export targets for the build tree
export(EXPORT "${PROJECT_NAME}Targets"
    FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Targets.cmake"
)

###################
# TEST EXECUTABLE #
###################
add_subdirectory("test")

if(MSVC_IDE)
  # set start up project
  if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.8.0")
    set(VS_STARTUP_PROJECT ${PROJECT_NAME})
  endif()
endif()
