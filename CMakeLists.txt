cmake_minimum_required(VERSION 3.0)

project(DSA
    VERSION 1.0.1
    LANGUAGES C CXX) 
    
# include config and dsa main header files
set(CONFIG_HEADER "${PROJECT_SOURCE_DIR}/config")
set(list_lib list)
include_directories(CONFIG_HEADER)

add_subdirectory(list)
add_subdirectory(linkedlist)
add_subdirectory(main)
