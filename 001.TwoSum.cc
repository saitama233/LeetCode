#include <iostream>
#include <vector>
#include <hash_map>
#include <algorithm>
using namespace std;
using namespace __gnu_cxx;

template<typename T>
void printer(const T& val) 
{
    cout << val << endl; 
}

//Brute Force
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ivec;
        for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
            for (vector<int>::iterator j = i+1; j < nums.end(); j++) {
                if (*i + *j == target) {
                    ivec.push_back(i - nums.begin());
                    ivec.push_back(j - nums.begin());
                    //在这里return稍微有点问题，要是没有等于目标的话会出错
                    //放在外层比较好
                    //return(ivec);
                    break;
                }
            }
        }
        return ivec;
    }
};

//Two-pass Hash Table
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        hash_map<int, int> hm;
        vector<int> ivec;
        for (int i = 0; i < nums.size(); i++) {
            hm[nums[i]] = i;
            //下面的添加方式也可以
            //hm.insert(make_pair(i, nums[i]));
        }

        //测试hashtable是否添加成功
        for (hash_map<int, int>::iterator i = hm.begin(); 
                i != hm.end(); i++) {
            cout << i->first << " " << i->second << endl;
        }

        for (int i = 0; i < nums.size(); i++) {
            hash_map<int, int>::iterator it = hm.begin();
            int complement = target - nums[i];
            if ((it = hm.find(complement)) != hm.end() && 
                    complement != nums[i]) {
                ivec.push_back(i);
                ivec.push_back(it->second);
                break;
            }
        }
        return ivec;
    }
};

int main(void) {
    vector<int> nums{3, 2, 4};
    Solution2 s;
    vector<int> res(s.twoSum(nums, 6));
    for_each(res.begin(), res.end(), printer<int>);
    return(0);
}
