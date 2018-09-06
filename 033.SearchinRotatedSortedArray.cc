// g++ -std=c++11
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        return bisearch(nums, 0, nums.size(), target);
    }
private:
	int bisearch(vector<int>& nums, int beg, int end, int target) {
		int mid = (beg + end) / 2;
        if (nums.empty())
            return -1;
        if (nums[mid] == target)
			return mid;
		if (beg + 1 >= end)
			return -1;
        if ((target > nums[mid] && target <= nums[end-1])           // 断点在左面，目标>mid
		        || (nums[end-1] < nums[mid] && target > nums[mid])    // 断点在右面，目标>mid
                || (target < nums[mid] && target <= nums[end-1] && nums[mid] > nums[end-1]))	// 断点在右面，目标<mid
			return bisearch(nums, mid + 1, end, target);
		else
			return bisearch(nums, beg, mid, target);
	}
};

void print(vector<int> &veci)
{
	vector<int>::iterator iter;
	for (iter = veci.begin(); iter != veci.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

int main()
{
	vector<pair<vector<int>,int> > vp;
	vp.push_back(make_pair<vector<int>,int>({4,5,6,7,8,9,1,2}, 1));
	vp.push_back(make_pair<vector<int>,int>({}, 1));
	vp.push_back(make_pair<vector<int>,int>({1}, 1));
	vp.push_back(make_pair<vector<int>,int>({1}, 0));
	vp.push_back(make_pair<vector<int>,int>({4,5}, 3));
	vp.push_back(make_pair<vector<int>,int>({4,5,6,7,0,1,2}, 0));
	vp.push_back(make_pair<vector<int>,int>({4,5,6,7,0,1,2}, 3));
	vp.push_back(make_pair<vector<int>,int>({1,3}, 1));
	vp.push_back(make_pair<vector<int>,int>({3,1}, 3));
	vp.push_back(make_pair<vector<int>,int>({7,8,1,2,3,4,5,6}, 2));
	vp.push_back(make_pair<vector<int>,int>({1,3,5}, 5));
	vp.push_back(make_pair<vector<int>,int>({3,4,1,2}, 4));
	Solution1 s;
	vector<pair<vector<int>,int> >::iterator iter;
	for (iter = vp.begin();
			iter != vp.end(); iter++) {
		cout << "vector: ";
		print((*iter).first);
		cout << "result: " << (*iter).second << " : " 
			 << s.search((*iter).first, (*iter).second) << endl;
	}
	return 0;
}
