
set(list_srcs 
    "list.c")

set(list_inc 
    "./")

add_library(${list_lib} STATIC
    ${list_srcs})

target_include_directories(${list_lib} PUBLIC 
    "${PROJECT_SOURCE_DIR}/config"
    "${list_inc}")