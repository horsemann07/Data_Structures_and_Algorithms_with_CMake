
set(stringg_src
"stringg.c")

set(stringg_incs
"./")

add_library(${stringg_lib} STATIC 
${stringg_src})

target_include_directories(${stringg_lib} PUBLIC 
    ${dsa_config}  
    ${stringg_incs})