#!/bin/bash

if [ $# -ne 1 ];then
    echo "Invalid parameters"
    return 255
fi

if [ ! -d "$1" ];then
    echo "directory doesn't exist"
    return 255
fi

cd "$1"

echo "Compiling..."
OUT_LOG="log.txt"
touch $OUT_LOG
g++ -Wall -std=c++11 ./*.cpp -o x.elf |& tee $OUT_LOG

errs=$(grep error $OUT_LOG)   # Find the word error in compiler output

# Check if the length of the string is greater than 1
if [[ ${#errs} -ge 1 ]];then
    echo "---------------------"
    echo "$errs"
    echo "Compilation failed..."
else
    fname="input.txt"
    echo "Testing..."
    
    # Run the program
    ./x.elf < $fname
fi

{
    cd -
}> /dev/null