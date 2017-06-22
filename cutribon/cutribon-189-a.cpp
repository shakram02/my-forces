#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef map<int, int> CutMap;

CutMap cut_map;

void build_up(int, int, vector<int> &);
int has_valid_cut(int x, int length, vector<int> &valid_cuts);

int n;
int **valid_cuttings; // All possible lengths * all possible cuts

int main()
{

    vector<int> cuts;
    cin >> n;

    valid_cuttings = (int **)calloc((n + 1) * 3, sizeof(char));

    int buff;
    while (cin >> buff)
        cuts.push_back(buff);

    sort(cuts.begin(), cuts.end());
    int result = 0;

#ifndef ONLINE_JUDGE
    cout << n << " " << cuts[0] << " " << cuts[1] << " " << cuts[2] << endl;
#endif

    cout << (has_valid_cut(6, 7, cuts) ? "Can do" : "No way") << endl;
    return 0;
}

void build_up(int cut, int length, vector<int> &valid_cuts)
{
    int cuts = 0;
    int index = 0;
    int try_cut = valid_cuts[index];
}

int best_cuts(int length, vector<int> &valid_cuts)
{
    int cut_index = 0;
    int cut = valid_cuts[cut_index];

    while (1)
    {
    }
    return 0;
}

int has_valid_cut(int x, int length, vector<int> &valid_cuts)
{
    if (valid_cuttings[length][x] != -1)
    {
        return valid_cuttings[length][x];
    }

    if (length - x == 0)
    {
        valid_cuttings[length][x] = 1;
        return true;
    }
    else if (length - x < 0)
    {
        valid_cuttings[length][x] = 0;
        return false;
    }

    for (const int &c : valid_cuts)
    {
        // Fill all the table
        has_valid_cut(c, length - x, valid_cuts);
    }

    return valid_cuttings[length][x];
}
