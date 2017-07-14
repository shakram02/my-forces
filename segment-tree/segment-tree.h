#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <cstddef>
#include <iomanip>
using namespace std;

void build(vector<int> &vals, int tree_index, int l, int r);
size_t sub_solve(size_t x, size_t y);
int segment_tree_main();
void update(int tree_index, int low, int high,
            int i, int j, int delta);
void print_tree();
void update_lazy(int tree_index, int a, int b,
                 int i, int j, int delta);
void query(int tree_index, int a, int b, int i, int j);