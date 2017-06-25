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
void read_vec_len(vector<T> &in_vec, std::size_t len)
{
    T buff;

    for (int i = 0; i < len; i++)
    {
        cin >> buff;
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
template <class T>
void read_2d_vector(int rows, int cols, vector<vector<T>> &container)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            T x;
            cin >> x;
            container[i][j] = x;
#ifndef ONLINE_JUDGE
            cout << "[" << i << "][" << j << "] " << container[i][j] << endl;
#endif
        }
    }
}

template <class T>
bool check_neighbors(int r_idx, int c_idx, int rows, int cols, T &grid, vector<pair<int, int>> available)
{
    T val;
    int start_row = (r_idx - 1 < 0) ? r_idx : r_idx - 1;
    int end_row = (r_idx + 1 > rows) ? r_idx : r_idx + 1;

    int start_col = (c_idx - 1 < 0) ? c_idx : c_idx - 1;
    int end_col = (c_idx + 1 > cols) ? c_idx : c_idx + 1;

    // See how many are alive
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_col; j <= end_col; j++)
        {
            if (grid[i][j] == val)
            {
                available.push_back(make_pair(i, j));
            }
        }
    }

    return available.size() != 0;
}

int main()
{
    vector<int> nums;
    string x = "4 2 1";
    split_parse(x, ' ', nums, to_int);

    for (auto i = nums.begin(); i != nums.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    vector<int> vec;
    sort(vec.begin(), vec.end(), greater<int>());

    return 0;
}
