#include <iostream>

using namespace std;

int main()
{
    unsigned int count;
    cin >> count;

    int buff;
    int min;

    for (unsigned int i = 0; cin && i < count; i++)
    {
        cin >> buff;
        if (buff == 1)
        {
            cout << -1 << endl;
            return 0;
        }

        if (buff < min)
        {
            min = buff;
        }
    }

    cout << 1 << endl;
    return 0;
}
