project( DOODLEJUMP )
cmake_minimum_required(VERSION 3.10.2)
#file( GLOB SRCS src/*.c src/*.cpp src/*.cc src/*.h src/*.hpp )  # a variable called SRCS with all files whose path match "*.c *.cpp..."
file( GLOB SRCS src/*.cc )  # a variable called SRCS with all files whose path match "*.c *.cpp..."
# The program we're compiling with the sources set above
add_executable( doodlejump ${SRCS} )

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})


# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(doodlejump ${SFML_LIBRARIES})

INSTALL(TARGETS doodlejump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
