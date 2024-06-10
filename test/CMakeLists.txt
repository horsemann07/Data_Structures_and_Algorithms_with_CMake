
set(test_utsrc 
    "test_main.c"
    "./stack/test_stack.c"
    "./queue/test_queue.c"
    "./list/test_list.c")

set(test_utincs "./include/")

add_executable(${test_main} ${test_utsrc})

target_include_directories(${test_main} PUBLIC 
    ${test_utincs} ${CMAKE_MODULE_PATH}  )

target_link_libraries(${test_main} PUBLIC 
    ${list_lib}
    ${stack_lib}
    ${queue_lib}
    unity) 

add_test(queue_test ${test_main})


