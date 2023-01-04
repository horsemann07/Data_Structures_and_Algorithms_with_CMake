
set(test_main "unit_tests")
set(test_utsrc 
    "test_main.c"
    "list_ut.c")
set(test_utincs "./include/")

add_executable(${test_main} ${test_utsrc})

target_include_directories(${test_main} PUBLIC 
    ${test_utincs})

target_link_libraries(${test_main} PUBLIC 
    ${list_lib}
    ${list_utest}
    unity) 

add_test(list_test ${test_main})