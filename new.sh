if [ $# -ne 2 ];then
    echo "Invalid parameters"
    echo "usage new [probname] [probnum-div]"
    return -1
fi

mkdir $1
cd $1
touch input.txt
touch "$1-$2.cpp"
cat << EOT >> "$1-$2.cpp"
 #include <iostream>
 #include <string>
 using namespace std;

 int main()
 {
     // Code
     return 0;
 }
EOT
{
    cd -
}> /dev/null