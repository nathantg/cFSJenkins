# This example toolchain file describes the cross compiler to use for
# the target architecture indicated in the configuration file.

# Basic cross system configuration
SET(CMAKE_SYSTEM_NAME           Linux)
SET(CMAKE_SYSTEM_VERSION        1)
SET(CMAKE_SYSTEM_PROCESSOR      arm)

# Specify the cross compiler executables
# Typically these would be installed in a home directory or somewhere
# in /opt.  However in this example the system compiler is used.
SET(CMAKE_C_COMPILER            "$ENV{ARM_ROOT}/../bin/arm-linux-gnueabihf-gcc")
SET(CMAKE_CXX_COMPILER          "$ENV{ARM_ROOT}/../bin/arm-linux-gnueabihf-g++")

# where is the target environment
SET(CMAKE_FIND_ROOT_PATH          "$ENV{ARM_ROOT}")

# SET(CMAKE_SYSROOT  "$ENV{ARM_ROOT}")

# Configure the find commands
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM  NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY  ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE  ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE  ONLY)
#SET(CMAKE_SYSTEM_INCLUDE_PATH "/home/canadensys/work/toolchains/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/arm-linux-gnueabihf")

# These variable settings are specific to cFE/OSAL and determines which 
# abstraction layers are built when using this toolchain
SET(CFE_SYSTEM_PSPNAME      "pc-linux")
SET(OSAL_SYSTEM_BSPNAME     "pc-linux")
SET(OSAL_SYSTEM_OSTYPE      "posix")

# Add the endianness specification (we're using little endian I believe) JZ Additions Here
SET(-D_EL DENDIAN=_EL)
