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
};

typedef vector<vector<Rectangle>> Cake;
Cake cake;
vector<vector<char>> letters;

void solve_case();
void read_case(int rows, int cols);
void sync_letters(Rectangle &r, char v);
void expand_rect(char val, Rectangle &original, Rectangle &x, char dir);

bool near_gap(Rectangle &to_check, int rows, int cols, Cake &grid,
              vector<Rectangle> &available);
bool are_aligned(Point &x, Point &y);
char get_expansion_direction(Rectangle &x, Rectangle &y);
bool is_empty_rect(const Rectangle &x);

string to_string(const Point &p);
Rectangle make_rect(const Point &a, const Point &b, const Point &c, const Point &d);

std::ostream &operator<<(std::ostream &strm, const Point &a);
std::ostream &operator<<(std::ostream &strm, const Rectangle &r);

// FIXME: def this when submitting
#undef ONLINE_JUDGE

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < 1; i++)
    {
        solve_case();
    }

    Rectangle r1 = make_rect(make_pair(0, 0), make_pair(0, 0),
                             make_pair(0, 0), make_pair(0, 0));

    Rectangle r2 = make_rect(make_pair(1, 0), make_pair(1, 0),
                             make_pair(1, 0), make_pair(1, 0));

    char d;

    if ((d = get_expansion_direction(r1, r2)))
    {
        expand_rect('x', r1, r2, d);
        cout << r1 << endl;
        Rectangle r = make_rect(make_pair(1, 0), make_pair(2, 0), make_pair(2, 1), make_pair(1, 1));
        cout << (is_empty_rect(r)) << endl;
    }
    else
    {
        cout << "can't expand" << endl;
    }

    return 0;
}

void solve_case()
{
    int rows, cols;
    cin >> rows;
    cin >> cols;
    Cake c(rows, vector<Rectangle>(cols));
    cake = c;
    letters = vector<vector<char>>(rows, vector<char>('?', cols));

    read_case(rows, cols);
}

bool near_gap(Rectangle &to_check, int rows, int cols, Cake &grid,
              vector<Rectangle> &available)
{
    // int top_r_idx = to_check.a.first;
    // int bottom_r_idx = to_check.d.first;
    // int start_row = (top_r_idx - 1 < 0) ? top_r_idx : top_r_idx - 1;
    // int end_row = (bottom_r_idx + 1 > rows) ? bottom_r_idx : bottom_r_idx + 1;

    // int left_c_idx = to_check.a.second;
    // int right_c_idx = to_check.d.second;
    // int start_col = (left_c_idx - 1 < 0) ? left_c_idx : left_c_idx - 1;
    // int end_col = (right_c_idx + 1 > cols) ? right_c_idx : right_c_idx + 1;

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

bool is_empty_rect(const Rectangle &x)
{
    for (int i = x.a.first; i < x.c.first; i++)
    {
        // Row scan
        for (int j = x.a.second; j < x.c.second; j++)
        {
            if (letters[i][j] != '?')
            {
                return false;
            }
        }
    }
    return true;
}

char get_expansion_direction(Rectangle &x, Rectangle &y)
{
    // Note, this function doesn't check adjacency
    // it's programmers problem
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

void expand_rect(char val, Rectangle &original, Rectangle &x, char dir)
{
    if (dir == 'v')
    {
        // Vertical expansion
        if (original.a < x.a) // Implied, orig.d < x.d
        {
            // Add the rect. below original
            // 0,0 : ORIG
            // 1,0 : X
            original.b = x.b;
            original.c = x.c;
        }
        else
        {
            // Add the rect. above the original
            original.a = x.a;
            original.d = x.d;
        }
    }
    else
    {
        // Horizontal expansion
        if (original.a < x.a) // Implied, orig.b < x.b
        {
            // Add the rect. to the right of original
            // 0,0 : ORIG .. 0,1 : X
            original.c = x.c;
            original.d = x.d;
        }
        else
        {
            // Add the rect. to the left of original
            // 0,0 : X .. 0,1 : ORIG
            original.a = x.a;
            original.b = x.b;
        }
    }
    sync_letters(original, val);
}

bool are_aligned(Point &x, Point &y)
{
    // Vertically or horizontally aligned
    return x.first == y.first || x.second == y.second;
}

bool is_not_boundary(int index, int limit)
{
    return index > 0 && index < limit;
}

void sync_letters(Rectangle &r, char v)
{
    cout << "start:" << r.a << " end" << r.c << endl;
    for (int i = r.a.first; i < r.c.first; i++)
    {
        for (int j = r.a.second; j < r.c.second; j++)
        {
            letters[i][j] = v;
            cout << i << " " << j << " " << letters[i][j] << endl;
        }
    }
}

void read_case(int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Rectangle x;
            char val;
            cin >> val;
            x.a = x.b = x.c = x.d = make_pair(i, j);
            cake[i][j] = x;
            letters[i][j] = val;

#ifndef ONLINE_JUDGE
            cout << letters[i][j] << " ";
#endif
        }
#ifndef ONLINE_JUDGE
        cout << endl;
#endif
    }
#ifndef ONLINE_JUDGE
    cout << endl;
#endif
}

Rectangle make_rect(const Point &a, const Point &b,
                    const Point &c, const Point &d)
{
    Rectangle x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    return x;
}

std::ostream &operator<<(std::ostream &strm, const Rectangle &r)
{
    return strm << "[" << r.a << "," << r.b << "," << r.c
                << "," << r.d << "] -> " << letters[r.a.first][r.a.second];
}

std::ostream &operator<<(std::ostream &strm, const Point &p)
{
    return strm << "(" << p.first << "," << p.second << ")";
}
