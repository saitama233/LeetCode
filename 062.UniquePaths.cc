/*
 * 62. Unique Paths
 * Medium
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * Example 2:
 * Input: m = 7, n = 3
 * Output: 28
 * 
 * Accepted 242,955
 * Submissions 533,822
*/

/* 回溯，1h，试了下[3,2]，[7,3]结果都是正确的，但[50,50]或[100,100]都超时了， */
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        int sum = 0;
        calsums(m - 1, n - 1, &sum);
        return sum;
    }
    void calsums(int x, int y, int *sum) {
        if (x == 0 && y == 0) {
            (*sum)++;
            return;
        }
        if (x > 0)
            calsums(x - 1, y, sum);
        if (y > 0)
            calsums(x, y - 1, sum);
    }
};

/* 回溯，20min，会比上个算法好些，但还是超时，Time Limit Exceeded */
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        int sum = 0;
        calsums(m - 1, n - 1, &sum);
        return sum;
    }
    void calsums(int x, int y, int *sum) {
        if (x == 0 || y == 0) {
            ++(*sum);
            return;
        }
        if (x > 0)
            calsums(x - 1, y, sum);
        if (y > 0)
            calsums(x, y - 1, sum);
    }
};

/* 动态规划：1.5h，初始化不是很简洁，虽然AC，但自己测试的话以int返回数特别大的时候leetcode网页测试貌似会溢出，暂时先不管了 */
/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths. 我觉得不准，， */
class Solution3 {
public:
    __u128 uniquePaths(int m, int n) {
        __u128 sum_arr[100][100] = {0};
        /* 先将上边和左边初始化为1，sum_arr[0][0]为0， */
        for (int i = 1; i < m; i++)
            sum_arr[i][0] = 1;
        for (int j = 1; j < n; j++)
            sum_arr[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum_arr[i][j] = sum_arr[i-1][j] + sum_arr[i][j-1];
            }
        }
        return sum_arr[m-1][n-1];
    }
};

int main()
{
    Solution1 s;
    return 0;
}
