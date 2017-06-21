#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int split_n_sum(const std::string &text, char sep, vector<int> &tokens);
std::string trim(string &);

int main()
{
    vector<int> coins;
    string buff;
    getline(cin, buff); // Skip the number

    getline(cin, buff);
    int sum = split_n_sum(buff, ' ', coins);

    sort(coins.begin(), coins.end());

#ifndef ONLINE_JUDGE
    cout << "Sum:" << sum << endl;
#endif

    int bro_sum = sum;
    int my_sum = 0;
    int count = 0;
    vector<int>::reverse_iterator it = coins.rbegin();

    while (my_sum <= bro_sum && it != coins.rend())
    {
        int val = *it;
        my_sum += val;
        bro_sum -= val;
        count++;
        it++;

#ifndef ONLINE_JUDGE
        cout << "My sum:" << my_sum << " Bro's sum:" << bro_sum << " Coin:" << *it << endl;
#endif
    }

    cout << count << endl;

    return 0;
}

int split_n_sum(const std::string &s, char sep, vector<int> &tokens)
{
    int sum = 0;
    for (size_t p = 0, q = 0; p != s.npos; p = q)
    {

        string x = s.substr(p + (p != 0), (q = s.find(sep, p + 1)) - p - (p != 0));

        if (x.length())
        {
            int coin = stoi(x);
            sum += coin;
            tokens.push_back(coin);
        }
    }

    return sum;
}
