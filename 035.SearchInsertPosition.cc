#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &veci)
{
	vector<int>::iterator iter;
	for (iter = veci.begin(); iter != veci.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		int mid;
        while (l < r) {
			mid = (l + r) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (target < nums[mid]) {
				r = mid;
			} else if (target > nums[mid]) {
				l = mid + 1;
			}
		}
		return l;
    }
};

int main(void)
{
	Solution s;
	vector<pair<vector<int>, int> >	vvi;
	vvi.push_back(make_pair<vector<int>, int>({1,3,5,6}, 5));
	vvi.push_back(make_pair<vector<int>, int>({1,3,5,6}, 2));
	vvi.push_back(make_pair<vector<int>, int>({1,3,5,6}, 7));
	vvi.push_back(make_pair<vector<int>, int>({1}, 8));
	vvi.push_back(make_pair<vector<int>, int>({}, 8));
	
	vector<pair<vector<int>, int> >::iterator iter;
	for (iter = vvi.begin(); iter != vvi.end(); iter++) {
		int pos = s.searchInsert((*iter).first, (*iter).second);
		cout << "the array is: " << endl;
		print((*iter).first);
		cout << "to insert: " << (*iter).second << endl;
		cout << pos << endl;
	}
}
