cmake_minimum_required(VERSION 3.10)

# Project details
project(DataStructure_Algorithm
    VERSION 0.0.1
    LANGUAGES C CXX)

# Set the name of the lib and path of config
set(dsa_config "${PROJECT_SOURCE_DIR}/config/")
include_directories(${dsa_config})

# # Set directory for libraries based on whether unit testing is enabled
# if(ENABLE_TESTING)
#     set(lib_directory "${CMAKE_BINARY_DIR}/unittest_${PROJECT_NAME}")
# else()
#     set(lib_directory "${CMAKE_BINARY_DIR}/${PROJECT_NAME}")
# endif()

# # Create the directory if it doesn't exist
# file(MAKE_DIRECTORY ${lib_directory})

# ------ set library names --------------- #
set(list_lib "list")
set(linkedlist_lib "linkedlist")
set(queue_lib "queue")
set(stack_lib "stack")
set(stringg_lib "stringg")
set(sorting_lib "sorting")
set(tree_lib "tree")
set(graph_lib "graph")
set(dsa_main "dsa_main")
set(test_main "unit_tests")

# Set C standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Global CMake variables
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Static tool analysis - CppCheck
set(CMAKE_CXX_CPPCHECK "cppcheck")

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--inconclusive"
            "--force" 
            "--inline-suppr"
            "--suppressions-list=${CMAKE_SOURCE_DIR}/build/CppCheckSuppressions.txt"
    )
endif()
# --------------------------------------------#
# include directory of library.
add_subdirectory(graph)
add_subdirectory(linkedlist)
add_subdirectory(list)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(stringg)
add_subdirectory(sorting)
add_subdirectory(tree)

# Options
option(USE_CONAN "Whether to use conan" OFF)
option(USE_VCPKG "Whether to use vcpkg" OFF)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

option(ENABLE_TESTING "Enable a Unit Testing build." OFF)
option(ENABLE_COVERAGE "Enable a Code Coverage build." OFF)

option(ENABLE_INCLUDE_WHAT_YOU_USE "Enable to add iwyu." OFF)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." OFF)
option(ENABLE_CPPCHECK "Enable to add cppcheck." ON)

option(ENABLE_SANITIZE_ADDR "Enable to sanitize address (Unix only)." OFF)
option(ENABLE_SANITIZE_UNDEF "Enable to sanitize undefined (Unix only)." OFF)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." OFF)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." ON)

option(ENABLE_LTO "Enable to add Link Time Optimization." OFF)

option(USE_CATCH2_LIB "Using Catch2 lib" OFF)

# Compiler-specific options
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-fdiagnostics-color=always)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fcolor-diagnostics)
endif()


# Enable coverage
if(ENABLE_COVERAGE)
    # Set the path to the directory containing the CodeCoverage.cmake file
    LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

# Build tests with gprof flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")

# Build tests with valgrind flags
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

if(ENABLE_TESTING)
    include(CTest)
    add_subdirectory(third_party)
    add_subdirectory(queue)
    add_subdirectory(stack)
    add_subdirectory(list)
    add_subdirectory(test)
    
    # Build unit tests with gprof flags
    
    
    if(ENABLE_COVERAGE)
        set(COVERAGE_MAIN "coverage")
        set(COVERAGE_EXCLUDES
            "${PROJECT_SOURCE_DIR}/doxygen/*"
            "${PROJECT_SOURCE_DIR}/config/*"
            "${PROJECT_SOURCE_DIR}/third_party/*"
            "${PROJECT_SOURCE_DIR}/build/*"
            "${PROJECT_SOURCE_DIR}/test/*"
            "/usr/include/*")

        # Generate coverage for unit tests
        setup_target_for_coverage_lcov(
            NAME ${COVERAGE_MAIN}_test
            EXECUTABLE ${test_main}
            EXCLUDE ${COVERAGE_EXCLUDES}
            DEPENDENCIES ${test_main})
    endif()
else()
    add_subdirectory(main)
endif()
