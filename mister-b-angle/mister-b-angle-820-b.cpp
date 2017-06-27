#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    double n, a;
    cin >> n;
    cin >> a;

    double angle = ((n - 2) * 180) / n;

    double division = angle / (n - 2);
    double err = n * angle;

    int current_v = 2; // matches the first and least division
    int optimal_dv = 1;

    for (int i = 0; i < n - 2; i++)
    {
        double curr_a = angle - (division * i);
        double temp = (a - curr_a) >= 0 ? (a - curr_a) : (-1 * (a - curr_a));

        if (temp < err)
        {
            optimal_dv = current_v;
            err = temp;
        }
        current_v++;
    }

    cout << n << " " << 1 << " " << optimal_dv << endl;

    return 0;
}
