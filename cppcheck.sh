#!/bin/bash

# Define the root directory to start the search
root_directory="."

# Find all C/C++ files recursively under the root directory
# and execute cppcheck on each file, saving the output to a log file
find "$root_directory" -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" |
while IFS= read -r file; do
    # Extract the directory containing the file
    dir=$(dirname "$file")

    # Run cppcheck on the file and save the output to a log file
    cppcheck "$file" 2>&1 | tee "$dir/log.txt" | {
        # Check if there were any errors reported by cppcheck
        if grep -q "error:"; then
            echo "Errors found in $file. See log.txt."
        else
            rm "$dir/log.txt" # Remove log file if no errors found
        fi
    }
done
