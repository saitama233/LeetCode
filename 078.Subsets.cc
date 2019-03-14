/*
 * 78. Subsets
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 *     [3],
 *     [1],
 *     [2],
 *     [1,2,3],
 *     [1,3],
 *     [2,3],
 *     [1,2],
 *     []
 * ]
 * Accepted 326,809     Submissions 644,212
*/

#include <iostream>
#include <vector>
using namespace std;

/*
 * 回溯，1.5h，一次AC，
 * Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
 * Memory Usage: 13.1 MB, less than 9.34% of C++ online submissions for Subsets.
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp_nums;
        dfs(nums.begin(), nums.end(), tmp_nums, res);
        return res;
    }
    
    void dfs(vector<int>::iterator cur, vector<int>::iterator end, 
            vector<int>& tmp_nums, vector<vector<int>> &res) {
        if (cur == end) {
            res.push_back(tmp_nums);
            return;
        }
        dfs(cur + 1, end, tmp_nums, res);
        tmp_nums.push_back(*cur);
        dfs(cur + 1, end, tmp_nums, res);
        tmp_nums.pop_back();
    }
};

int main()
{
    return 0;
}
