#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>::iterator tmp;
		vector<int>::iterator pos;
		int sum = 0;
        int val;
		
		if (height.size() < 2)
			return sum;
		
		for (pos = height.begin() + 2; pos < height.end(); pos++) {
			val = *(pos - 1) + 1;
			tmp = pos - 1;
			// calculate from the bottom，
			while (val <= *pos) {
				// try to find the same level before this position，
				while (tmp >= height.begin()) {
					if (*tmp >= val) {
						sum += pos - tmp - 1;
						break;
					}
					tmp--;
				}
				val++;
			}
		}
		return sum;
    }
};

int main()
{
	Solution s;
	vector<pair<vector<int>, int> >	vvi;
	vvi.push_back(make_pair<vector<int>, int>({5,7}, 0));
	vvi.push_back(make_pair<vector<int>, int>({10,9,8,9,10}, 4));
	vvi.push_back(make_pair<vector<int>, int>({4,2,3}, 1));
	vvi.push_back(make_pair<vector<int>, int>({3,2,4,1,2}, 2));
	vvi.push_back(make_pair<vector<int>, int>({0,1,0,2,1,0,1,3,2,1,2,1}, 6));
	
	vector<pair<vector<int>, int> >::iterator iter;
	for (iter = vvi.begin(); iter != vvi.end(); iter++) {
		int sum = s.trap(iter->first);
		cout << "The sum is " << sum << endl;
		if (sum != iter->second) {
			cout << "The expected sum is " << iter->second 
                 << ", The result is wrong" << endl;
		}
	}
	
	return 0;
}
