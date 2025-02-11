# CMake version
cmake_minimum_required(VERSION 3.22)
set(CMAKE_SYSTEM_NAME Generic)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Define project name and used language
project(Lab7_LCD C)  # ASM CXX

# MCU and programmer settings
set(MCU atmega32)
set(MCU2 m32)
set(PROGRAMMER usbasp)
set(F_CPU 8000000UL)

# Collect .c files
file(GLOB ${PROJECT_NAME}_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Include directories
set(${PROJECT_NAME}_INCLUDE_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../COTS/STD_LIB/"
)

# MCAL and HAL libraries
set(MCAL_LIBS
    MDIO
    MPORT
)

set(HAL_LIBS
    HLCD
)

# Add subdirectories for MCAL libraries
foreach(var ${MCAL_LIBS})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../COTS/LIB/MCAL/${var} ${CMAKE_BINARY_DIR}/${var})
endforeach()

# Add subdirectories for HAL libraries
foreach(var ${HAL_LIBS})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../COTS/LIB/HAL/${var} ${CMAKE_BINARY_DIR}/${var})
endforeach()

# Set compiler
set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")

# AVR-specific paths
find_path(AVR_INCLUDE_DIR avr/io.h
  PATHS "/usr/lib/avr/include" "/usr/avr/include"
  REQUIRED
)

# Compiler/Linker Flags
add_compile_options(
  -mmcu=${MCU}
  -DF_CPU=${F_CPU}
  -Os
  -Wall
  -Wextra
  -ffunction-sections
  -fdata-sections
  -I${AVR_INCLUDE_DIR}  # Explicitly include AVR headers
)

add_link_options(
  -mmcu=${MCU}
  -Wl,--gc-sections     # Remove unused sections
)

# Prevent host system headers from being used
include_directories(${AVR_INCLUDE_DIR})
set(CMAKE_C_FLAGS "-nostdinc")

# Debugging messages
message(STATUS "${${PROJECT_NAME}_SRC_FILES}")
message(STATUS "${CMAKE_C_COMPILER}")
message(STATUS "${AVR_INCLUDE_DIR}")

# Flash flags
set(FLASH_FLAGS "-R .eeprom -R .lock -R .signature")

# Create executable
add_executable(${PROJECT_NAME}.elf ${${PROJECT_NAME}_SRC_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME}.elf ${MCAL_LIBS} ${HAL_LIBS})

# Include directories for the target
target_include_directories(${PROJECT_NAME}.elf PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")

# Macro to flash and burn the program
macro(FlashAndBurn)
    add_custom_target(flash
        ALL
        DEPENDS ${PROJECT_NAME}.elf
        COMMAND avr-objcopy ${FLASH_FLAGS} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        COMMENT "Generating .hex file from .elf"
    )

    # Modify the clean build rule to delete the .hex file
    set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${PROJECT_NAME}.hex)

    add_custom_target(burn
        DEPENDS flash
        COMMAND avrdude -c ${PROGRAMMER} -p ${MCU2} -U flash:w:${PROJECT_NAME}.hex:i -B 1
        VERBATIM
        COMMENT "Burning .hex file"
    )
endmacro()

# Call the macro to set up flashing and burning
FlashAndBurn()