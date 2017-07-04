#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
typedef unsigned long long ll;
ll count, ratio;

int main()
{
    cin >> count >> ratio;

    ll dipl = count / (2 * (ratio + 1));
    cout << dipl << " " << dipl * ratio << " " << count - (dipl * (ratio + 1)) << endl;
    return 0;
}
