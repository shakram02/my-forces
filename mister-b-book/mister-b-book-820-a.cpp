#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;

    if (v0 >= c)
    {
        cout << 1 << endl;
        return 0;
    }

    // Skip day one0
    int days = 1;
    int c_page = v0;
    int speed = v0;
    if (speed + a < v1)
    {
        speed += a;
    }
    else if (speed + a >= v1)
    {
        speed = v1;
    }

    while (c_page < c)
    {
        days++;
        c_page += (speed - l);
        if (speed + a < v1)
        {
            speed += a;
        }
        else if (speed + a >= v1)
        {
            speed = v1;
        }
    }
    cout << days << endl;

    return 0;
}
