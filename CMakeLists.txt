cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0048 NEW)
PROJECT(jemu65c02 VERSION 0.5.1)

INCLUDE(CheckSymbolExists)

#includes
INCLUDE_DIRECTORIES(include)

#source files
AUX_SOURCE_DIRECTORY(src DANGERFARM_SOURCES)

ADD_EXECUTABLE(buildsite ${DANGERFARM_SOURCES})

TARGET_COMPILE_OPTIONS(
    buildsite PRIVATE -g -O0
                     -Wall -Werror -Wextra -Wpedantic
                     -Wno-unused-command-line-argument)
