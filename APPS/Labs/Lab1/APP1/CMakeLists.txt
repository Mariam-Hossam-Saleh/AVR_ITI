# cmake version
cmake_minimum_required(VERSION 3.22)

# define project name + used language
project(Lab1App1 C) # ASM CXX

# set compiler
find_program(CMAKE_C_COMPILER NAME avr-gcc PATH "usr/bin/")

# collect .c files
file(GLOB ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)
set(${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c")

# set include paths 
set(${PROJECT_NAME}_LIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Inc/)
set(STDLIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/STD_LIB/)

# collect .h files
file(GLOB ${PROJECT_NAME}LIB_INC_FILES ${MCAL_LIB_INC_PATH}*.h)
file(GLOB STDLIB_INC_FILES ${STDLIB_INC_PATH}*.h)
set(${PROJECT_NAME}_INC_FILES ${${PROJECT_NAME}LIB_INC_FILES} ${LIB_INC_FILES})

# just for debugging 
message(STATUS "${${PROJECT_NAME}_SOURCES}")
message(STATUS "${CMAKE_C_COMPILER}")
message(STATUS "${${PROJECT_NAME}_SRC_FILES}")
message(STATUS "${STDLIB_INC_PATH}")


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../../COTS/LIB/MCAL/MDIO ${CMAKE_BINARY_DIR}/MDIO_build)
# create static library
# library target

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC_FILES})

# specify header access method for anyone wanting to link to this lib
#include directory to the target
target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_LIB_INC_PATH})
target_include_directories(${PROJECT_NAME} PUBLIC ${STDLIB_INC_PATH})

#set_target_properties(${PROJECT_NAME} )
target_link_libraries(${PROJECT_NAME} MDIO)