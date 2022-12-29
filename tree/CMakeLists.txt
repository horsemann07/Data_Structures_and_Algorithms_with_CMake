
set(tree_src
"tree.c")

set(tree_incs
"./")

add_library(${tree_lib} STATIC 
${tree_src})

target_include_directories(${tree_lib} PUBLIC
    ${dsa_config}
    ${tree_incs})