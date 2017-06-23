#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef map<int, map<int, int>> BoundMap;
BoundMap memo;

/* ##### */
template <class T>
void read_vec(vector<T> &in_vec);
template <class T>
void print_vec(vector<T> &in_vec);
/* ##### */

int get_count(vector<int> &samples, int start, int end);
int flip(int index, vector<int> samples);

int main()
{
    int count;
    cin >> count;
    vector<int> samples;
    read_vec(samples);

    get_count(samples, 0, samples.size() - 1);

    return 0;
}

int get_count(vector<int> &samples, int start, int end)
{
    int result = -1;

    if (memo.count(start) && memo[start].count(end))
    {
        result = memo[start][end];
        return result;
    }
    else if (start == end)
    {
        result = flip(start, samples);
    }
    else if (start <= -1 || end >= (int)samples.size() || start > end || end < start)
    {
        result = 0; // Invalid bounds
    }
    else
    {
        int max_count = 0;
        for (int c_end = end; c_end >= start; c_end--)
        {
            for (int c_start = start; c_start < end; c_start++)
            {
                max_count = max(flip(c_start, samples) + get_count(samples, c_start + 1, c_end), max_count);
            }
        }
        result = max_count;
    }

#ifndef ONLINE_JUDGE
    if (start <= end)
    {
        cout << "Set [" << start << "] [" << end << "] ->" << result << endl;
    }
#endif
    memo[start][end] = result;
    return result;
}

int flip(int index, vector<int> samples)
{
    return 1 - samples[index];
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