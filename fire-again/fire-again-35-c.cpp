#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> point_t;

int forest[2000][2000] = {0};
int max_depth = 0;
int rows, count, init_burning;
point_t last_point;
set<point_t> start_points;

void get_near(pair<int, int> p, set<pair<int, int>> &n);
bool are_all_burnt(vector<pair<int, int>> &o);

#ifndef ONLINE_JUDGE
void print(set<pair<int, int>> &v)
{
    for (auto const &x : v)
    {
        cout << "(" << x.first + 1 << "," << x.second + 1 << ") ";
    }
    cout << endl;
}
#endif

pair<int, int> get_first(set<pair<int, int>> &s)
{
    pair<int, int> head = *start_points.begin();
    start_points.erase(head);

    return head;
}

int main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> rows >> count >> init_burning;

    for (int i = 0; i < init_burning; i++)
    {
        int x, y;
        cin >> x >> y;
        y--;
        x--;
        start_points.insert(make_pair(x, y));
    }

    last_point = *start_points.begin(); // Base case
    set<point_t> to_visit;

    while (!start_points.empty())
    {
        point_t pivot = get_first(start_points);
        set<point_t> n;
        get_near(pivot, n);

        if (forest[pivot.first][pivot.second])
        {
            // If it's burnt, I mut've calculated the neighbors
            continue;
        }

#ifndef ONLINE_JUDGE
        cout << "Burning: " << pivot.first + 1 << "," << pivot.second + 1 << endl;
        print(n);
#endif

        forest[pivot.first][pivot.second] = 1;
        last_point = pivot;
        for (auto const &p : n)
        {
            if (forest[p.first][p.second])
            {
                continue;
            }
            to_visit.insert(p);
        }

        if (start_points.empty())
        {
#ifndef ONLINE_JUDGE
            cout << endl;
#endif
            for (auto const &x : to_visit)
            {
                if (forest[x.first][x.second])
                {
                    continue;
                }
                start_points.insert(x);
            }
            to_visit.clear();
        }
    }

    cout << last_point.first + 1 << " " << last_point.second + 1 << endl;
    return 0;
}

bool are_all_burnt(vector<pair<int, int>> &o)
{
    for (auto const &x : o)
    {
        if (forest[x.first][x.second] == 0)
        {
            return false;
        }
    }
    return true;
}

void get_near(pair<int, int> p, set<pair<int, int>> &n)
{
    int r_idx = p.first;
    int c_idx = p.second;
    int start_row, end_row, start_col, end_col;

    start_row = (r_idx == 0) ? r_idx : r_idx - 1;
    end_row = (r_idx + 1 >= rows) ? r_idx : r_idx + 1;

    start_col = (c_idx == 0) ? c_idx : c_idx - 1;
    end_col = (c_idx + 1 >= count) ? c_idx : c_idx + 1;

    for (int i = start_row; i <= end_row; i++)
    {

        if (i == r_idx)
        {
            continue;
        }

        n.insert(make_pair(i, c_idx));
    }

    for (int j = start_col; j <= end_col; j++)
    {
        if (j == c_idx)
        {
            continue;
        }

        n.insert(make_pair(r_idx, j));
    }
}
