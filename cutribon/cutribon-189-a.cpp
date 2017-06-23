#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

// Length -> [cut length -> validity]
typedef map<int, map<int, int>> CutMap;

CutMap cut_map;
int has_valid_cut(int cut_index, int length, vector<int> &valid_cuts, CutMap &memo);
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
        int will_cut = 0;

        while ((will_cut = has_valid_cut(cuts[i], rope_length, cuts, memo)))
        {
            count++;
            rope_length -= cuts[i];
#ifndef ONLINE_JUDGE
            cout << "Cut [" << cuts[i] << "]" << endl;
#endif
        }
    }

    cout << count << endl;
    return 0;
}

int has_valid_cut(int cut, int length, vector<int> &valid_cuts, CutMap &memo)
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
        // length > cut
        for (const int &c : valid_cuts)
        {
            // Get all possible values of other cuts
            int len_after_cut = length - cut;
            int temp = has_valid_cut(c, len_after_cut, valid_cuts, memo);
            memo[len_after_cut][c] = temp;

            if (temp)
            {
                result = 1;
            }
        }

        // No sub-solution found
        if (result == -1)
        {
            result = 0;
        }
    }

#ifndef ONLINE_JUDGE
    cout << " [" << cut << "] cuts [" << length << "] -> " << result << endl;
#endif
    return result;
}
