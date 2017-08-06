#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int count;
    cin >> count;

    int global_max = 0;
    int local_max = 0;
    char c;
    
    string text;
    
    getline(cin,text);  // Read the number and ignore it
    getline(cin,text);
    
    
    for(unsigned int i=0; i < text.length(); i++){
        c = text[i];

        if(c >= 'A' && c <= 'Z'){
            local_max++;
            global_max = max(local_max, global_max);
        }
        
        if(c == ' '){
            local_max = 0;
        }
    }

    cout << global_max << endl;
    return 0;
}
