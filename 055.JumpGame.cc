/*
 * 55. Jump Game
 * Medium
 * 
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 *              jump length is 0, which makes it impossible to reach the last index.
 * Accepted
 * 215,608
 * Submissions
 * 703,097
*/

/*
 * 5次AC，用时2.5h
 * Runtime: 12 ms, faster than 57.96% of C++ online submissions for Jump Game.
 * 第一次理解错题目了，(maximum jump length at that position)
 * 第二次使用回溯超时了，，
 * 第三四五次都是一个算法，有点细节逻辑搞错了，有些急躁，没怎么检查连续提交
 */

#include <iostream>
#include <vector>
using namespace std;

/* wrong answer：回溯，超时了 */
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    
    bool dfs(vector<int>& nums, int idx, int last) {
        if (idx >= last) {
            return true;
        }
        for (int i = nums[idx]; i > 0; i--) {
            idx += i;
            if (dfs(nums, idx, last))
                return true;
            idx -= i;
        }
        return false;
    }
};

/* 遍历数组，遇到0便向前遍历，检查是否能越过这个0，
 * 越不过返回false，可以越过继续遍历，
 * 退出循环或当前下标i + nums[i]大于等于最后下标返回true，
 */
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (i + nums[i] >= size - 1)
                return true;
            if (nums[i] == 0) {
                int j;
                for (j = i - 1; j >= 0; j--) {
                    if (nums[j] > i - j)
                        break;
                }
                if (j < 0)
                    return false;
            }
        }
        return true;
    }
};

void print(vector<int> &nums)
{
    vector<int>::iterator iter;
    cout << "{";
    for (iter = nums.begin(); iter != nums.end(); iter++) {
        cout << *iter;
        cout << (iter + 1 == nums.end() ? "" : ",");
    }
    cout << "}" << endl;
}

int main()
{
    Solution1 s;
    vector<pair<vector<int>, bool>> input;
    bool res;
    
    input.push_back(make_pair<vector<int>, bool>({}, true));
    input.push_back(make_pair<vector<int>, bool>({2,3,1,1,4}, true));
    input.push_back(make_pair<vector<int>, bool>({3,2,1,0,4}, false));
    input.push_back(make_pair<vector<int>, bool>({2,3,1,3,4}, true));
    input.push_back(make_pair<vector<int>, bool>({2,5,0,0}, true));
    
    vector<pair<vector<int>, bool>>::iterator iter;
    for (iter = input.begin(); iter < input.end(); iter++) {
        print(iter->first);
        res = s.canJump(iter->first);
        if (res != iter->second)
            cout << "The result is wrong: " << res << endl;
        else
            cout << "The result is right: " << res << endl;
    }
    
    return 0;
}
