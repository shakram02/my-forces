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

    if (k > n * n)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n && k > 0; i++)
    {
        mat[i][i] = 1;
        k--;

        if (k >= 2)
        {
            // Fan out
            for (int j = i; j < n && (k > 1); j++)
            {
                if (i == j)
                {
                    continue;
                }
                mat[i][j] = 1;
                mat[j][i] = 1;
                k -= 2;
            }
        }
    }

    // No need to check for k > 0 here as when building the matrix
    // I can choose wheter to fan out ( -2 ) or walk on diagonal ( -1 )
    // with having a move that consumes 1 step, I can generate all
    // sequences

    print_mat(mat);

    return 0;
}
