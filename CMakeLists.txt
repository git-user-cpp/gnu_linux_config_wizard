cmake_minimum_required(VERSION 3.30)
project(gnu_linux_config_wizard)

# Set the C standard to gnu11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define compile options for debug and release builds
#set(CMAKE_C_FLAGS_DEBUG "-g")
#set(CMAKE_C_FLAGS_RELEASE "-O2")

# Add compile options
add_compile_options(
    -Wall
    -Wextra
    -std=gnu11
    -Wconversion
    -Wshadow
    -Wstrict-prototypes
    -Wmissing-prototypes
    -Wmissing-declarations
    -Wcast-align
    -Wpointer-arith
    -Wformat=2
    -Wwrite-strings
    -Wswitch-enum
    -Wunreachable-code
    -Wundef
    -Wredundant-decls
    -Wfloat-equal
)

# Add the executable
add_executable(gnulinwiz src/linux_setup.c src/main.c)
