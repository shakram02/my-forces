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
g++ -Wall -std=c++11 ./*.cpp -o x.elf

fname="input.txt"
echo "Testing..."

# Run the program
./x.elf < $fname

{
    cd -
}> /dev/null