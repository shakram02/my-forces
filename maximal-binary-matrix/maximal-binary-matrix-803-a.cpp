#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_mat(vector<vector<int>> &mat)
{
    int dim = mat.size();
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    if (k > n && (k - n) % 2 != 0)
    {
        // Not symmetric
        cout << -1 << endl;
        return 0;
    }
    if (k > n * n)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n && k > 0; i++)
    {
        mat[i][i] = 1;
        k--;
    }

    // Fill the rest of the matrix
    for (int i = 0; (i < n) && k > 0; i++)
    {
        for (int j = 1; (j < n) && k > 0; j++)
        {
            if (i + j >= n)
            {
                continue;
            }
            mat[i][i + j] = 1;
            mat[i + j][i] = 1;
            k -= 2;
        }
    }

    print_mat(mat);

    return 0;
}
