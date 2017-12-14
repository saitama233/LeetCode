#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void printer(const T& val) 
{
    cout << val << endl; 
}

//Brute Force
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
            for (vector<int>::iterator j = i+1; j < nums.end(); j++) {
                if (*i + *j == target) {
                    vector<int> ivec;
                    ivec.push_back(i - nums.begin());
                    ivec.push_back(j - nums.begin());
                    return(ivec);
                }
            }
        }
    }
};

int main(void) {
    vector<int> nums{3, 2, 4};
    Solution1 s;
    vector<int> res(s.twoSum(nums, 6));
    for_each(res.begin(), res.end(), printer<int>);
    return(0);
}
