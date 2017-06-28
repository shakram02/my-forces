#!/bin/bash
if [ $# -ne 2 ];then
    echo "Invalid parameters"
    echo "usage new [probname] [probnum-div]"
    exit -1
fi

if [ -d "$1" ];then
    echo "Directory exists"
    exit -1
fi

# Create the file template
mkdir "$1"
cd "$1"
touch input.txt
touch "$1-$2.cpp"
cat << EOT >> "$1-$2.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    return 0;
}
EOT

# Don't show the output of cd -
{
    cd -
}> /dev/null