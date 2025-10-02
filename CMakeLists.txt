cmake_minimum_required(VERSION 4.0)
project(justasimpleccal C)

set(CMAKE_C_STANDARD 11)

# Find GTK4 with pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_executable(justasimpleccal main.c
        login.c
)

target_link_libraries(${PROJECT_NAME} ${GTK4_LIBRARIES})
