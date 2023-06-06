
set(test_utsrc 
    "test_main.c"
    "list_ut.c" 
    "./stack/test_stack.c"
    "./queue/test_queue.c")

set(test_utincs "./include/")

add_executable(${test_main} ${test_utsrc})

target_include_directories(${test_main} PUBLIC 
    ${test_utincs} ${CMAKE_MODULE_PATH}  )

target_link_libraries(${test_main} PUBLIC 
    ${list_lib}
    ${list_utest}
    ${stack_lib}
    ${queue_lib}
    unity) 

add_test(list_test ${test_main})


