/*
 * 64. Minimum Path Sum
 * Medium
 * 
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * Input:
 * [
 *     [1,3,1],
 *     [1,5,1],
 *     [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * Accepted 197,725
 * Submissions 442,437
*/

/* DP，1h20min， */
/* Runtime: 8 ms, faster than 96.91% of C++ online submissions for Minimum Path Sum. */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dparr;
        int m, n;
        for (m = 0; m != grid.size(); m++) {
            vector<int> tmp;
            for (n = 0; n != grid[m].size(); n++) {
                int cur = 0, left = 0, up = 0;
                if (m && n) {
                    left = tmp[n-1];
                    up = dparr[m-1][n];
                    cur = grid[m][n] + (left < up ? left : up);
                } else if (m && !n) {
                    up = dparr[m-1][n];
                    cur = grid[m][n] + up;
                } else if (!m && n) {
                    left = tmp[n-1];
                    cur = grid[m][n] + left;
                } else {
                    cur = grid[m][n];
                }
                cout << "grid[m][n]: " << grid[m][n] 
                     << ",left: " << (left ? left : 0)
                     << ",up: " << (up ? up : 0)
                     << ",cur: " << cur << endl;
                tmp.push_back(cur);
            }
            dparr.push_back(tmp);
            tmp.clear();
        }
        if (m == 0)
            return 0;
        else
            return dparr[m-1][n-1];
    }
};

int main()
{
    return 0;
}
