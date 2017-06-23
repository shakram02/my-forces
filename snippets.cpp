#include <iostream>
#include <string>
#include <vector>
using namespace std;

string trim(string &str)
{
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}

template <class T>
void split_parse(const std::string &s, char sep, vector<T> &tokens, T (*parser)(string))
{

    for (size_t p = 0, q = 0; p != s.npos; p = q)
    {
        string x = s.substr(p + (p != 0), (q = s.find(sep, p + 1)) - p - (p != 0));
        tokens.push_back(parser(x));
    }
}

#include <regex>
string replace(const string &str, const string &regex, const string &repl)
{
    std::regex reg(regex);
    return regex_replace(str, reg, repl);
}

template <class T>
void read_vec(vector<T> &in_vec)
{
    T buff;

    while (cin >> buff)
    {
        in_vec.push_back(buff);
    }
}

template <class T>
void print_vec(vector<T> &in_vec)
{
    for (const auto &x : in_vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int to_int(string s)
{
    return stod(s);
}

int main()
{
    vector<int> nums;
    string x = "4 2 1";
    split_parse(x, ' ', nums, to_int);

    for (auto i = nums.begin(); i != nums.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    return 0;
}
