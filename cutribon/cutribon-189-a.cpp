#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

// Length -> [cut length -> validity]
typedef map<int, map<int, int>> CutMap;

int get_cut_count(int cut_index, int length, vector<int> &valid_cuts, CutMap &memo);
int max_cuts_at(int length, CutMap &memo);

CutMap cut_map;
int rope_length;

const int NUM_CUTS = 3;
int main()
{

    vector<int> cuts;
    cin >> rope_length;

    CutMap memo;

    int buff;
    while (cin >> buff)
        cuts.push_back(buff);

    int count = 0;
    sort(cuts.begin(), cuts.end());

#ifndef ONLINE_JUDGE
    cout << rope_length << " " << cuts[0] << " " << cuts[1] << " " << cuts[2] << endl;
#endif

    for (int i = 0; i < NUM_CUTS; i++)
    {
        int temp_rope_length = rope_length;
        int temp_cut_count = 0;

        temp_cut_count = get_cut_count(cuts[i], temp_rope_length, cuts, memo);

        if (temp_cut_count > count)
        {
            count = temp_cut_count;
        }
    }

    cout << count << endl;
    return 0;
}

int get_cut_count(int cut, int length, vector<int> &valid_cuts, CutMap &memo)
{
    int result = -1;
    if (memo.count(length) && memo[length].count(cut))
    {
        result = memo[length][cut];
    }
    else if (cut == 0 || length <= 0)
    {
        result = 0;
    }
    else if (cut == length)
    {
        result = 1;
    }
    else if (cut > length)
    {
        result = 0;
    }
    else
    {
        int max_cuts = 0;
        // length > cut
        for (unsigned int i = 0; i < valid_cuts.size(); i++)
        {
            int c = valid_cuts[i];
            // Get all possible values of other cuts
            int len_after_cut = length - cut;
            int temp = get_cut_count(c, len_after_cut, valid_cuts, memo);

            if (temp)
            {
                // Find the max subcuts
                max_cuts = max(max_cuts_at(len_after_cut, memo) + 1, temp);
#ifndef ONLINE_JUDGE
                cout << " {" << max_cuts_at(len_after_cut, memo) + 1 << "} ? {" << temp << "}" << endl;
#endif
            }
        }

        result = max_cuts;
    }

#ifndef ONLINE_JUDGE
    if (result != 0)
    {
        cout << " [" << cut << "] cuts [" << length << "] -> " << result << endl;
    }
#endif

    memo[length][cut] = result;
    return result;
}

int max_cuts_at(int length, CutMap &memo)
{
    int max = 0;
    for (const auto &cut_info : memo[length])
    {
        int number = cut_info.second;
        if (number > max)
        {
            max = number;
        }
    }

    return max;
}
