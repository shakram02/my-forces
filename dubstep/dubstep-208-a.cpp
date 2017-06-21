#include <iostream>
#include <string>
#include <regex>

using namespace std;

string trim(string &);

int main()
{
    std::regex wubs("(WUB)+");
    std::regex spaces("\\s{2,}");
    string buffer;
    getline(cin, buffer);

    string unwubbed = regex_replace(buffer, wubs, " ");
    unwubbed = regex_replace(unwubbed, spaces, " ");

    cout << trim(unwubbed) << endl;

#ifndef ONLINE_JUDGE
    cout << "|" << unwubbed << "|" << endl;
#endif
    return 0;
}

string trim(string &str)
{
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}