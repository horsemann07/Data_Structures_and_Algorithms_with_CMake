
set(linkedlist_src
    "linkedlist.c")

set(linkedlist_incs
    "./")

add_library(linkedlist STATIC 
    ${linkedlist_src})

target_include_directories(linkedlist PUBLIC 
    ${linkedlist_incs})