
set(tree_src
"binary_tree.c")

set(tree_incs
"./")

add_library(${tree_lib} STATIC 
${tree_src})

target_include_directories(${tree_lib} PUBLIC
    ${dsa_config}
    ${tree_incs})

target_link_libraries(${tree_lib} PUBLIC ${stack_lib} ${queue_lib})