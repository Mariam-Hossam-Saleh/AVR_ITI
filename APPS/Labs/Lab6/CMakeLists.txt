# cmake version
cmake_minimum_required(VERSION 3.22)
set(CMAKE_SYSTEM_NAME Generic)

# set C && Cpp versions
set(CMAKE_C_STANDARD 99)

# define project name + used language
project(Lab6 C) # ASM CXX

set(MCU atmega32)
set(MCU2 m32)
set(PROGRAMMER usbasp)
set(F_CPU 8000000UL)

# set compiler
# find_program(CMAKE_C_COMPILER NAME avr-gcc PATH "usr/bin/")

# collect .c files
file(GLOB ${PROJECT_NAME}_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
set(${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# set include paths 
#set(${PROJECT_NAME}_LIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/inc)
#set(STDLIB_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/STD_LIB/)

# collect .h files
#file(GLOB ${PROJECT_NAME}_LIB_INC_FILES ${MCAL_LIB_INC_PATH}*.h)
#file(GLOB STDLIB_INC_FILES ${STDLIB_INC_PATH}*.h)
#set(${PROJECT_NAME}_INC_FILES ${${PROJECT_NAME}_LIB_INC_FILES} ${STDLIB_INC_FILES})


# Include directories
set(${PROJECT_NAME}_INCLUDE_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/STD_LIB/"
)

set(HAL_LIBS
HLED
HSEVENSEG
)

set(MCAL_LIBS
MDIO
MPORT
)

foreach(var ${HAL_LIBS})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../COTS/LIB/HAL/${var} ${CMAKE_BINARY_DIR}/${var})
# create static library
# library target
 endforeach()

foreach(var ${MCAL_LIBS})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../COTS/LIB/MCAL/${var} ${CMAKE_BINARY_DIR}/${var})
# create static library
# library target
 endforeach()

set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")
add_compile_options(-mmcu=${MCU} -g -Wall -Os -DF_CPU=${F_CPU})

add_link_options(-mmcu=${MCU} -Wl,--gc-sections)

# just for debugging 
message(STATUS "${${PROJECT_NAME}_SOURCES}")
message(STATUS "${CMAKE_C_COMPILER}")
message(STATUS "${${PROJECT_NAME}_SRC_FILES}")
message(STATUS "${STDLIB_INC_PATH}")

set(FLASH_FLAGS "-R .eeprom -R .lock -R .signature")

add_executable(${PROJECT_NAME}.elf ${${PROJECT_NAME}_SRC_FILES} ${${PROJECT_NAME}_LIB_INC_FILES})
#set_target_properties(${PROJECT_NAME} )
target_link_libraries(${PROJECT_NAME}.elf ${HAL_LIBS})

# specify header access method for anyone wanting to link to this lib
# include directory to the target
target_include_directories(${PROJECT_NAME}.elf PUBLIC ${${PROJECT_NAME}_INCLUDE_DIR} )
#target_include_directories(${PROJECT_NAME}.elf PUBLIC ${STDLIB_INC_PATH})

# command to extract hex from elf (avr-objcopy -O ihex Lab2App1.elf Lab2App1.hex)
macro(FlashAndBurn)

    add_custom_target(flash
        ALL
        DEPENDS ${PROJECT_NAME}.elf
        COMMAND avr-objcopy ${FLASH_FLAGS} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        COMMENT "Generating .hex file from .elf"
   
    )

    # modify the clean build rule to delete the .hex file
    set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${PROJECT_NAME}.hex)

    add_custom_target(burn
        DEPENDS flash
        COMMAND avrdude -c ${PROGRAMMER} -p ${MCU2} -U flash:w:${PROJECT_NAME}.hex:i -B 1
        VERBATIM
        COMMENT "Burnning .hex file"
   
    ) 
endmacro()
FlashAndBurn()
