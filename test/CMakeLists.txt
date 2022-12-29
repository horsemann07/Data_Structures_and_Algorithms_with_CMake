set(test_main "unit_tests")
set(test_src "test_main.c")
set(test_incs "./")


add_executable(${test_main} ${test_src})
target_include_directories(${test_main} PUBLIC ${test_incs})
target_link_libraries(${test_main} PIBLIC 
    ${list_lib}
    unity::unity 
    Catch2::Catch2 ) 