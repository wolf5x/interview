// TODO test
/**
 * Find arbitary local minimum cell in the 2D grid.
 * A local minimum cell is a cell whose number
 * is less than its neighbor up/down/left/right grid's
 *
 * ps. Assume no duplicate numbers in the grid.
 */
#include <vector>
using std::vector;

vector<pair<int,int> > localMinimum2D(vector<vector<int> > grid)
{
    int m = grid.size(), n = m>0 ? grid[0].size() : 0;
    assert(n > 0 && "Empty grid.");
    int lo = 0, up = m-1;
    while(lo < up) {
        int mi = (lo+up)/2;
        int col = findMaxColumn(grid, mi);
        if (mi > lo && grid[mi][col] < grid[mi-1][col]) {
            hi = mi-1;
        } else if (mi < hi && grid[mi][col] < grid[mi+1][col]) {
            lo = mi+1;
        } else {
            return make_pair(mi, col);
        }
    }
    return make_pair(lo, findMaxColumn(grid, lo));
}

int findMaxColumn(vector<vector<int> > &grid, int row)
{
    int ans = 0;
    for (int i = 1; i < grid[row].size(); i++) {
        if (grid[row][i] > grid[row][ans]) {
            ans = i;
        }
    }
    return ans;
}

