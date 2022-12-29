cmake_minimum_required(VERSION 3.0)

project(DataStructure_Algorithm
    VERSION 0.0.1
    LANGUAGES C CXX) 
    
# set the name of the lib and path of config
set(dsa_config "${PROJECT_SOURCE_DIR}/config/")
include_directories(${dsa_config})

set(list_lib "list")
set(linkedlist_lib "linkedlist")
set(queue_lib "queue")
set(stack_lib "stack")
set(stringg_lib "stringg")
set(sorting_lib "sorting")
set(tree_lib "tree")
set(graph_lib "graph")
set(dsa_main "dsa_main")

# include(FetchContent)
# FetchContent_Declare(
#     unity
#     GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity
#     GIT_TAG v2.5.2
#     GIT_SHALLOW FALSE)
# FetchContent_MakeAvailable(unity)

# FetchContent_Declare(
#     Catch2
#     GIT_REPOSITORY https://github.com/catchorg/Catch2
#     GIT_TAG v2.13.9
#     GIT_SHALLOW TRUE)
# FetchContent_MakeAvailable(Catch2)

# include directory of library.
add_subdirectory(graph)
add_subdirectory(linkedlist)
add_subdirectory(list)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(stringg)
add_subdirectory(sorting)
add_subdirectory(tree)
add_subdirectory(main)
# add_subdirectory(third_party)