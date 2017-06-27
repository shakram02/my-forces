#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
void read_2d_vector(int rows, int cols, vector<vector<T>> &container)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            T x;
            cin >> x;
            container[i][j] = x;
#ifndef ONLINE_JUDGE
            cout << "[" << i << "][" << j << "] " << container[i][j] << endl;
#endif
        }
    }
}

bool check_row_col(int n, int r, int c, vector<vector<int>> &container);

int main()
{
    int size;
    cin >> size;
    vector<vector<int>> lab(size, vector<int>(size, 0));
    read_2d_vector(size, size, lab);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (lab[i][j] == 1)
            {
                continue;
            }
            if (check_row_col(lab[i][j], i, j, lab) == false)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

bool check_row_col(int n, int r, int c, vector<vector<int>> &container)
{
    bool result = false;
    int size = container.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
#ifndef ONLINE_JUDGE
            cout << "[" << i << "][" << c << "] " << container[i][c]
                 << "[" << r << "][" << j << "] " << container[r][j] << endl;
#endif
            if (container[i][c] + container[r][j] == n)
            {
                return true;
            }
        }
    }

    return result;
}
