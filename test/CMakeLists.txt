
set(test_utsrc 
    "test_main.c"
    "list_ut.c" 
    "./stack/test_stack.c")

set(test_utincs "./include/")

add_executable(${test_main} ${test_utsrc})

target_include_directories(${test_main} PUBLIC 
    ${test_utincs} ${CMAKE_MODULE_PATH}  )

target_link_libraries(${test_main} PUBLIC 
    ${list_lib}
    ${list_utest}
    ${stack_lib}
    unity) 

add_test(list_test ${test_main})

# if(ENABLE_COVERAGE)
# target_include_directories(${test_main} PUBLIC ${CMAKE_MODULE_PATH}  )
# set(COVERAGE_MAIN "coverage")
#         set(COVERAGE_EXCLUDES
#             "${PROJECT_SOURCE_DIR}/doxygen/*"
#             "${PROJECT_SOURCE_DIR}/config/*"
#             "${PROJECT_SOURCE_DIR}/tests/*"
#             "${PROJECT_SOURCE_DIR}/build/*"
#             "/usr/include/*")
#         setup_target_for_coverage_lcov(
#             NAME
#             ${COVERAGE_MAIN}
#             EXECUTABLE
#             ${test_main}
#             DEPENDENCIES
#             ${test_main})
# endif()


