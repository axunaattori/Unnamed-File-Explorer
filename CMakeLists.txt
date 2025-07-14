cmake_minimum_required(VERSION 4.0)
project(Unnamed_File_Explorer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES src/*.c src/*.cpp)

add_compile_options(-Wall)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NOTCURSES REQUIRED notcurses)

add_executable(ufe ${SRC_FILES})

target_link_libraries(ufe PRIVATE ${NOTCURSES_LIBRARIES})
target_include_directories(ufe PRIVATE ${NOTCURSES_INCLUDE_DIRS})
