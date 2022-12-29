
set(queue_src
    "queue.c")

set(queue_incs
    "./")

add_library(${queue_lib} STATIC 
    ${queue_src})

target_include_directories(${queue_lib} PUBLIC 
    ${dsa_config}
    ${queue_incs})