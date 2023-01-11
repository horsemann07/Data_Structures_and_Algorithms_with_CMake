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

# include directory of library.
add_subdirectory(graph)
add_subdirectory(linkedlist)
add_subdirectory(list)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(stringg)
add_subdirectory(sorting)
add_subdirectory(tree)

option(ENABLE_TESTING "Enable the testing" OFF)
option(USE_CATCH2_LIB "Using Catch2 lib" OFF)
if(ENABLE_TESTING)
    include(CTest)
    add_subdirectory(testing_lib)
    add_subdirectory(test)
    # set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
    # add_definitions(-fprofile-arcs -ftest-coverage)
    # link_libraries(gcov)
    # set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} --coverage)

    # add_custom_target(cov gcov ${CMAKE_CURRENT_SOURCE_DIR}/test/test_main.c --object-directory 
    # ${CMAKE_CURRENT_BINARY_DIR}/test/CMakeFiles/unit_tests.dir WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    
else()
    add_subdirectory(main)
endif()

