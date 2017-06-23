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
/* ##### */

int get_count(vector<int> &samples, int start, int end);
int ones_outside_range(vector<int> &samples, int start, int end);
int flip(int index, vector<int> samples);

int main()
{
    int count;
    cin >> count;
    vector<int> samples;
    read_vec(samples);

    int start = 0;
    int end = samples.size() - 1;
    int max_count = 0;

    for (int c_end = end; c_end >= start; c_end--)
    {
        for (int c_start = start; c_start <= end; c_start++)
        {
            int ones_in_range = get_count(samples, c_start, c_end) + ones_outside_range(samples, c_start, c_end);
#ifndef ONLINE_JUDGE
            cout << "[" << c_start << " " << c_end << "]:" << ones_in_range << endl;
#endif
            if (ones_in_range > max_count)
            {
                max_count = ones_in_range;
            }
        }
    }
    cout << max_count << endl;

    return 0;
}

int get_count(vector<int> &samples, int start, int end)
{
    int result = -1;

    if (memo.count(start) && memo[start].count(end))
    {
        result = memo[start][end];
    }
    else if (start == end)
    {
        result = flip(start, samples);
    }
    else if (start <= -1 || end >= (int)samples.size() || start > end || end < start)
    {
        return -1; // Invalid bounds, don't register invalid entries in table
    }
    else
    {
        result = flip(start, samples) + get_count(samples, start + 1, end);
    }

#ifndef ONLINE_JUDGE
    cout << "Set [" << start << "] [" << end << "] ->" << result << endl;
#endif

    memo[start][end] = result;
    return result;
}

int flip(int index, vector<int> samples)
{
    return 1 - samples[index];
}

int ones_outside_range(vector<int> &samples, int start, int end)
{
    int ones = 0;
    for (int i = 0; i < (int)samples.size(); i++)
    {
        if (i >= start && i <= end)
        {
            continue;
        }
        if (samples[i])
        {
            ones++;
        }
    }

    return ones;
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
