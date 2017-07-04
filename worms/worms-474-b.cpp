#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

template <class T>
void read_vec(vector<T> &in_vec, int len)
{
    T buff;

    for (int i = 0; i < len; i++)
    {
        cin >> buff;
        in_vec.push_back(buff);
    }
}

int find_pile(int worm_label, int start_idx, int end_idx, const vector<int> &pile_info);
int in_pile(int worm, int pile_index, const vector<int> &pile_info);
void convert_pile_info(vector<int> &pile_info);

int main()
{
    int num_piles;
    cin >> num_piles;
    vector<int> pile_info;
    read_vec(pile_info, num_piles);
    int x;
    cin >> x;
    vector<int> labels;
    read_vec(labels, x);
    convert_pile_info(pile_info);

#ifndef ONLINE_JUDGE
    for (const int &x : pile_info)
    {
        cout << x << " ";
    }
    cout << endl;
#endif

    for (const int &label : labels)
    {
        cout << find_pile(label, 0, num_piles, pile_info) << endl;
    }

    return 0;
}

int find_pile(int worm_label, int start_idx, int end_idx, const vector<int> &pile_info)
{
    int pivot_idx = (start_idx + end_idx) / 2;
    int test_in_pile = in_pile(worm_label, pivot_idx, pile_info);

#ifndef ONLINE_JUDGE
    cout << "[" << setw(3) << pile_info[start_idx]
         << " | " << setw(3) << pile_info[pivot_idx]
         << " | " << setw(3) << pile_info[end_idx] << " ]: Worm:" << worm_label;
    cout << " In pile " << setw(3) << pivot_idx << " ? " << test_in_pile << endl;
#endif
    switch (test_in_pile)
    {
    case 0:
        return pivot_idx + 1;
    case 1:
        return find_pile(worm_label, pivot_idx, end_idx, pile_info);
    case -1:
        return find_pile(worm_label, start_idx, pivot_idx, pile_info);
    }
    return -1;
}

int in_pile(int worm, int pile_index, const vector<int> &pile_info)
{
    //-1  0 1
    // >  == <
    int result = -1;

    if (pile_index == ((int)pile_info.size() - 1) && worm >= pile_info[pile_index])
    {
        result = 0;
    }
    else if (worm >= pile_info[pile_index] && worm < pile_info[pile_index + 1])
    {
        result = 0;
    }
    else if (worm > pile_info[pile_index])
    {
        result = 1;
    }
    else if (worm < pile_info[pile_index])
    {
        result = -1;
    }

    return result;
}

void convert_pile_info(vector<int> &pile_info)
{
    int acc = 1;
    pile_info.insert(pile_info.begin(), 0);
    for (unsigned int i = 0; i < pile_info.size(); i++)
    {
        acc += pile_info[i];
        pile_info[i] = acc; // Convert worm count to pile start index
    }
}
