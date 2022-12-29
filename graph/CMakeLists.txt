
set(graph_src
    "graph.c")

set(graph_incs
    "./")

add_library(${graph_lib} STATIC 
    ${graph_src})

target_include_directories(${graph_lib} PUBLIC 
    ${dsa_config}
    ${graph_incs})