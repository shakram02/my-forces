#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <queue>

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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> sleeps;
    queue<int> week;
    read_vec_len(sleeps, n);

    double sum = 0.0;
    double sum_week = 0.0;

    // Prep the first week
    for (int i = 0; i < k; i++)
    {
        week.push(sleeps[i]);
        sum_week += sleeps[i];
    }

    // Sum over all other weeks
    for (int i = k; i < n; i++)
    {
        sum += sum_week;
#ifndef ONLINE_JUDGE
        cout << "w:" << sum_week << endl;
#endif
        sum_week -= week.front();
        sum_week += sleeps[i];
        week.pop();
        week.push(sleeps[i]);
    }
    sum += sum_week; //TODO: keep this?
#ifndef ONLINE_JUDGE
    cout << "w:" << sum_week << endl;
#endif

    cout.precision(numeric_limits<double>::max_digits10);
    cout << (sum / (n - k + 1.0)) << endl;
    return 0;
}