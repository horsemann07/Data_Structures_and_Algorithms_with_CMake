
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
cmake ..

# build
make
