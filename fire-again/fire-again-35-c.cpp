#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
typedef pair<int, int> point_t;

int rows, count, init_burning;
point_t last_point;
vector<point_t> start_points;

#ifndef ONLINE_JUDGE
void print(vector<vector<int>> &f)
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < count; j++)
        {
            cout << setw(3) << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
#endif

int main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> rows >> count >> init_burning;

    vector<vector<int>> forest(rows, vector<int>(count, rows + count));

    for (int i = 0; i < init_burning; i++)
    {
        int x, y;
        cin >> x >> y;
        y--;
        x--;
        start_points.push_back(make_pair(x, y));
    }

    last_point = start_points[0]; // Base case
    int max_depth = 0;
    // Burn the first generation (start points), then the second (to_visit), ...etc
    for (auto const &p : start_points)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < count; j++)
            {
                int val = abs(i - p.first) + abs(j - p.second);
                forest[i][j] = min(val, forest[i][j]);
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (forest[i][j] > max_depth)
            {
                max_depth = forest[i][j];
                last_point = make_pair(i, j);
            }
        }
    }

#ifndef ONLINE_JUDGE
    print(forest);
    cout << "Max depth:" << max_depth << endl;
#endif

    cout << last_point.first + 1 << " " << last_point.second + 1 << endl;
    return 0;
}
