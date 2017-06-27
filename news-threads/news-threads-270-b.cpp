#include <iostream>
#include <string>
#include <vector>

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
    int c;
    cin >> c;
    vector<int> t;
    read_vec_len(t, c);
    
    for (auto i = t.size() - 1; i >= 1; i--)
    {
        if (t[i] > t[i - 1])
        {
            continue;
        }
        cout << i << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
