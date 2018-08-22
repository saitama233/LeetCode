#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution {
public:
    void nextPermutation(vector<int>& nums) {
		vector<int>::iterator iter, si;
        if (nums.size() <= 1)
            return;
        
        // 从最后找递减队列的结束，
        for (iter = nums.end() - 1; 
                iter != nums.begin() && *iter <= *(iter-1);) {
			iter--;
		}
        sort(iter, nums.end());
        // 判断下，否则si = iter - 1;会越界
        if (iter != nums.begin()) {
            // 寻找比si的下一个值，就是稍微比si大的值，然后交换
            for (si = iter - 1; *iter <= *si;)
                iter++;
            swap(*si, *iter);
        }
    }
};

void print(vector<int> &vi)
{
    for (int i = 0; i < vi.size(); i++) {
        cout << vi[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    solution s;
    vector<vector<int> > nums{{1,4,6}};
    nums.push_back({1,2,3});
    nums.push_back({2,2,3});
    nums.push_back({});
    for (int i = 0; i < nums.size(); i++) {
        cout << "before: ";
        print(nums[i]);
        s.nextPermutation(nums[i]);
        cout << "after: ";
        print(nums[i]);
    }
    return 0;
}
