
set(stack_src
    "stack.c")

set(stack_incs
    "./")

add_library(${stack_lib} STATIC 
    ${stack_src})

target_include_directories(${stack_lib} PUBLIC 
    ${dsa_config}  
    ${stack_incs})