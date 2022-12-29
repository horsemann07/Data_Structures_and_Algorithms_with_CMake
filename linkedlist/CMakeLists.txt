
set(linkedlist_src
    "linkedlist.c")

set(linkedlist_incs
    "./")

add_library(${linkedlist_lib} STATIC 
    ${linkedlist_src})

target_include_directories(${linkedlist_lib} PUBLIC 
    ${dsa_config}  
    ${linkedlist_incs})