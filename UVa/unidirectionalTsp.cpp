#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int INF = (unsigned int)(-1) >> 1;

int grid[10][100];
short parent[10][100];

int rows, cols;
int w(const int& n) { 
    return (n == -1 ? rows-1 : n % rows);
}

void p(int row, int col) {
    if(col == cols) return;
    cout << row+1 << (col < cols-1 ? ' ' : '\n');
    p(w(row + parent[row][col]), col+1); 
}

// Note for future David:
// In this problem, the path that ENDS lexicographically smallest
// may not START lexicograpahically smallest, because of the wrapping.
// This may also be the case for any problem where paths aren't
// necessarily contiguous in the normal sense.
// For this reason, it makes sense to propigate backwards.  An optimal
// path backwards is also an optimal path forward, since the 'graph' is
// undirected.  Then you can reconstruct the path from the front, and you
// know that a path that STARTS lexicographically smallest, IS
// lexicographically smallest.

// Thought: Is it a good idea to always do this, just in case?

int main() {
    while(cin >> rows >> cols) {
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                cin >> grid[i][j];

        for(int j = cols-2; j >= 0; --j)
            for(int i = 0; i < rows; ++i) {
                int minRight = INF;
                for(int r = -1; r <= 1; ++r){
                    int rightVal = grid[w(i+r)][j+1];
                    if(rightVal <= minRight) {
                        if(rightVal == minRight &&
                           w(i+r) >= w(i+parent[i][j])) {
                            continue;
                        }
                        minRight = rightVal;
                        parent[i][j] = r;
                    }
                }
                grid[i][j] += minRight;
            }

        int minRow = 0;
        for(int i = 1; i < rows; ++i)
            if(grid[i][0] < grid[minRow][0])
                minRow = i;

        p(minRow, 0);
        cout << grid[minRow][0] << endl;
    }

    return 0;
}
