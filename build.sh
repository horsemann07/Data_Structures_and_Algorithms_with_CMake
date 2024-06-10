
# get current dir
cur_dir=$(pwd)

echo "${cur_dir}"

cd ${cur_dir}

# del build dir 
rm -dr build

#make build dir
mkdir build

# goto build
cd build

# cmake config
cmake -DCMAKE_BUILD_TYPE=Debug .. 

# build
cmake --build . --target all

if [[ $1 == '-t' ]];then
    # run test
    ctest

    # run test with valgrind
    valgrind --leak-check=full --show-leak-kinds=all ./unit_tests

    # # Run your executable to generate gmon.out
    ./unit_tests

    # # Run gprof to generate the profile report
    gprof ./unit_tests gmon.out > profile_report.txt

    # generate coverage

    make coverage_test
else 
    # run code with valgrind
    valgrind --leak-check=full --show-leak-kinds=all ./main/dsa_main > valgrind_output.txt 2>&12222

    # Run your executable to generate gmon.out
    ./main/dsa_main


    # # Run gprof to generate the profile report
    gprof ./main/dsa_main gmon.out > profile_report.txt

fi



