#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
void read_vec(vector<T> &in_vec)
{
    T buff;

    while (cin >> buff)
    {
        in_vec.push_back(buff);
    }
}

int main()
{
    int num = 0;
    cin >> num;

    vector<int> welfare;
    read_vec(welfare);
    sort(welfare.begin(), welfare.end(), greater<int>());

    int wealthiest = welfare[0];
    int spent_money = 0;
    for (int i = 1; i < (int)welfare.size(); i++)
    {
        spent_money += wealthiest - welfare[i];
    }

    cout << spent_money << endl;
    return 0;
}
