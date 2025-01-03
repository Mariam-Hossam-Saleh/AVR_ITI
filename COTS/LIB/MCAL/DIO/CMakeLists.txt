# cmake version
cmake_minimum_required(VERSION 3.22)

# define project name + used language
project(DIO C) # ASM CXX

# collect .c files
file(GLOB ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)

# set include paths 
set(${PROJECT_NAME}_LIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Inc/)
set(STDLIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../STD_LIB/)

# collect .h files
file(GLOB ${PROJECT_NAME}LIB_INC_FILES ${MCAL_LIB_INC_PATH}*.h)
file(GLOB STDLIB_INC_FILES ${STDLIB_INC_PATH}*.h)
set(${PROJECT_NAME}_INC_FILES ${${PROJECT_NAME}LIB_INC_FILES} ${LIB_INC_FILES})

# specify include dir
include_directories(
    ${${PROJECT_NAME}_LIB_INC_PATH}
    ${STDLIB_INC_PATH}
)

# create static library
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC_FILES} ${${PROJECT_NAME}_INC_FILES})

# specify header access method for anyone wanting to link to this lib
target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_LIB_INC_PATH})
target_include_directories(${PROJECT_NAME} PUBLIC ${STDLIB_INC_PATH})
