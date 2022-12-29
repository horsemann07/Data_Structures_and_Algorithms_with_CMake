
add_executable(${dsa_main} "dsa_main.c")

target_include_directories(${dsa_main} PUBLIC 
    ${dsa_config})

target_link_libraries(${dsa_main} PUBLIC 
    ${list_lib} 
    ${linkedlist_lib}
    ${queue_lib}
    ${stack_lib}
    ${tree_lib}
    ${graph_lib}
    ${sorting_lib}
    ${stringg_lib})
