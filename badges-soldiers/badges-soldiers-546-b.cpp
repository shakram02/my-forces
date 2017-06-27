#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> nums;

int main()
{
    int len;
    int amount = 0;
    int buff;

    cin >> len;
    for (auto i = 0; cin && i < len; i++)
    {
        cin >> buff;
        while (nums.count(buff))
        {
            buff++;
            amount++;
        }
        nums.insert(buff);
    }
    cout << amount << endl;
    return 0;
}
