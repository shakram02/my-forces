#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> Point;

// 4 points are chosen to ease the exapansion validation
// though 2 points are suffecient to make a rect.
struct Rectangle
{
    /*
        A----D
        |    |
        |    |
        |    |
        B----C
    */
    Point a;
    Point b;
    Point c;
    Point d;
    char val;
};

typedef vector<vector<Rectangle>> Cake;

void solve_case();
void read_case(int rows, int cols, Cake &cake);
bool near_gap(Rectangle &to_check, int rows, int cols, Cake &grid, vector<Rectangle> &available);
bool are_aligned(Point &x, Point &y);
char get_expansion_direction(Rectangle &x, Rectangle &y);
Rectangle make_rect(const Point &a, const Point &b, const Point &c, const Point &d);

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < 1; i++)
    {
        solve_case();
    }
    cout << (make_pair(0, 0) == make_pair(0, 0)) << endl;
    Rectangle r1 = make_rect(make_pair(0, 0), make_pair(1, 0), make_pair(1, 0), make_pair(0, 0));
    Rectangle r2 = make_rect(make_pair(0, 1), make_pair(1, 1), make_pair(1, 1), make_pair(0, 1));
    cout << (get_expansion_direction(r1, r2)) << endl;
    return 0;
}

void solve_case()
{
    int rows, cols;
    cin >> rows;
    cin >> cols;
    Cake cake(rows, vector<Rectangle>(cols));
    read_case(rows, cols, cake);
}

Rectangle make_rect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    Rectangle x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    return x;
}
bool near_gap(Rectangle &to_check, int rows, int cols, Cake &grid, vector<Rectangle> &available)
{

    // int start_row = (r_idx - 1 < 0) ? r_idx : r_idx - 1;
    // int end_row = (r_idx + 1 > rows) ? r_idx : r_idx + 1;

    // int start_col = (c_idx - 1 < 0) ? c_idx : c_idx - 1;
    // int end_col = (c_idx + 1 > cols) ? c_idx : c_idx + 1;

    // // See how many are alive
    // for (int i = start_row; i <= end_row; i++)
    // {
    //     for (int j = start_col; j <= end_col; j++)
    //     {
    //         if (grid[i][j] == '?')
    //         {
    //             available.push_back(make_pair(i, j));
    //         }
    //     }
    // }

    return available.size() != 0;
}

char get_expansion_direction(Rectangle &x, Rectangle &y)
{
    if (are_aligned(x.a, y.b) && are_aligned(x.d, y.c))
    {
        // Vertically aligned
        return 'v';
    }
    if (are_aligned(x.a, y.d) && are_aligned(x.b, y.c))
    {
        // Horizontally aligned
        return 'h';
    }
    return 0;
}

bool are_aligned(Point &x, Point &y)
{
    return x.first == y.first || x.second == y.second;
}

bool is_not_boundary(int index, int limit)
{
    return index > 0 && index < limit;
}

void read_case(int rows, int cols, Cake &cake)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Rectangle x;
            cin >> x.val;
            x.a = x.b = x.c = x.d = make_pair(i, j);
            cake[i][j] = x;
            cout << i << " " << j << " :" << cake[i][j].val << endl;
        }
    }
}
