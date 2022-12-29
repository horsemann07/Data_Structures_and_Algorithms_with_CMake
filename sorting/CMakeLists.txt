

set(sorting_src
"sorting.c")

set(sorting_incs
"./")

add_library(${sorting_lib} STATIC 
${sorting_src})

target_include_directories(${sorting_lib} PUBLIC 
    ${dsa_config}  
    ${sorting_incs})

target_link_libraries(${sorting_lib} PUBLIC ${list_lib})