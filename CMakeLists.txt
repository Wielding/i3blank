cmake_minimum_required(VERSION 3.21)
project(i3blank C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 99)

add_executable(i3blank main.c)

target_link_libraries(i3blank ${GTK4_LIBRARIES})