#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

template <class T>
void read_vec_len(vector<T> &in_vec, std::size_t len)
{
    T buff;

    for (unsigned int i = 0; cin && i < len; i++)
    {
        cin >> buff;
        in_vec.push_back(buff);
    }
}

map<int, vector<int>> employees;
map<int, int> counts;
int get_depth(int man, int prev);

int main()
{
    int count;
    cin >> count;
    vector<int> input;
    read_vec_len(input, count);

    // Populate the tree
    int depth = 0;
    for (int i = 0; i < count; i++)
    {
        int man_of_i = input[i];

        employees[man_of_i].push_back(i + 1);
    }

    // Flatten the results
    for (map<int, vector<int>>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        int d = get_depth(it->first, 0);
        depth = max(d, depth);
    }

    cout << depth << endl;
    return 0;
}

int get_depth(int man, int prev)
{

    if (counts[man] != 0)
        return counts[man];

    if (employees[man].size() == 0)
        return 0;

    int result = prev + 1;

    for (const int &x : employees[man])
    {
        result = max(result, get_depth(x, prev + 1));
    }

    counts[man] = result;
    return result;
}
