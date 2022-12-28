
add_executable(MAIN dsa_main.c)

target_include_directories(MAIN PUBLIC CONFIG_HEADER)
target_link_libraries(MAIN PUBLIC ${list_lib} linkedlist)