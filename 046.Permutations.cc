#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 本来想用回溯了，不过感觉有些麻烦，而且一旦有重复的数字没想出来怎么算，
 * 想起来之前做Next Permutation的时候在网上看过全排列可以用Next Permutation生成，就用这个了，
 * Runtime: 12 ms, faster than 42.63% of C++ online submissions for Permutations.
 * 发现答案里比较好的算法还是用的回溯，，
 */
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>     vvec;
        
        sort(nums.begin(), nums.end());
        vvec.push_back(nums);
        if (!nums.size()) {
            return vvec;
        }
        while (next_permutation(nums) != -1) {
            vvec.push_back(nums);
        }
        
        return vvec;
    }
    
private:
    int next_permutation(vector<int> &nums) {
        vector<int>::iterator front;
        vector<int>::iterator behind;
        for (front = nums.end() - 1; front != nums.begin(); front--) {
            if (*front > *(front - 1))
                break;
        }
        if (front == nums.begin())
            return -1;
       
        for (behind = nums.end() - 1; behind >= front; behind--) {
            if (*behind > *(front - 1)) {
                swap(behind, front - 1);
                break;
            }
        }
        sort(front, nums.end());
        return 0;
    }
    
    void swap(vector<int>::iterator a, vector<int>::iterator b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
};

// 40min，回溯法，扫了一眼4ms的答案，直接写出来了，一次AC，
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0);

        return res;
    }
private:
    void dfs(vector<vector<int>> &res, vector<int>& nums, int pos) {
        if (pos + 1 == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            dfs(res, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
};

void print(vector<int> &vec)
{
    vector<int>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter;
        cout << (iter + 1 == vec.end() ? '\n' : ',');
    }
}

int main()
{
    Solution1 s;
    vector<vector<int>> vvec;
    vector<vector<int>> ret;
    vvec.push_back({});
    vvec.push_back({1,2,3,4});
    vvec.push_back({1,1,2});
    
    vector<vector<int>>::iterator viter;
    vector<vector<int>>::iterator riter;
    vector<int>::iterator iter;
    for (viter = vvec.begin(); viter != vvec.end(); viter++) {
        cout << "The vector: ";
        print(*viter);
        ret = s.permute(*viter);
        cout << "The result is:\n";
        cout << "{" << endl;
        for (riter = ret.begin(); riter != ret.end(); riter++) {
            cout << "\t{";
            for (iter = (*riter).begin(); iter != (*riter).end(); iter++) {
                cout << *iter;
                cout << (iter + 1 == (*riter).end() ? "" : ",");
            }
            cout << "}" << endl;
        }
        cout << "}\n" << endl;
    }
    
    return 0;
}
