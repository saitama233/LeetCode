#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;
        int l = 0, r = nums.size();
        int mid;
		
        // 先找到最左面的边界
		while (l < r) {
            mid = (l + r) / 2;
			if (nums[mid] == target)
				left = mid;
			if (target <= nums[mid])
				r = mid;
			if (target > nums[mid])
				l = mid + 1;
		}
        // cout << left << endl;
        // 再找到最右面的边界
		l = 0; r = nums.size();
		while (l < r) {
            mid = (l + r) / 2;
			if (nums[mid] == target)
				right = mid;
			if (target >= nums[mid])
				l = mid + 1;
			if (target < nums[mid])
				r = mid;
		}
        // cout << right << endl;
		
		return vector<int>{left, right};
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

int main(void)
{
	Solution s;
	vector<pair<vector<int>, int> >	vvi;
	vvi.push_back(make_pair<vector<int>, int>({5,7,7,8,8,10}, 8));
	vvi.push_back(make_pair<vector<int>, int>({5,7,7,8,8,10}, 6));
	vvi.push_back(make_pair<vector<int>, int>({1}, 1));
	vvi.push_back(make_pair<vector<int>, int>({}, 8));
	
	vector<pair<vector<int>, int> >::iterator iter;
	for (iter = vvi.begin(); iter != vvi.end(); iter++) {
		vector<int> v = s.searchRange((*iter).first, (*iter).second);
		cout << "the array is: " << endl;
		print((*iter).first);
		cout << "to find: " << (*iter).second << endl;
		cout << "{" << v[0] << ", " << v[1] << "}" << endl;
	}
}
