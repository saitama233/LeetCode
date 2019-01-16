/*
 * 70. Climbing Stairs
 * Easy
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * Example 2:
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * Accepted 333,639          Submissions 778,728
 */

#include <iostream>
using namespace std;

/* DP，20min，和斐波那契数列有点类似，两次AC，第一次对0和1这种边界判断的逻辑出了点问题， */
/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs. */
class Solution {
public:
    int climbStairs(int n) {
        int arr[n];
        if (n < 3)
            return n;
        arr[0] = 1;
        arr[1] = 2;
        for (int i = 2; i < n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n-1];
    }
};

int main()
{
    return 0;
}
