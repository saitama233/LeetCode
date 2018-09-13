#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > 	res;
		vector<int> 			tmp;
        int 					sum = 0;
		
		sort(candidates.begin(), candidates.end());
        trace_combinationsum(candidates, tmp, res, sum, target, 0);
		return res;
    }
private:
    void trace_combinationsum(vector<int>& candidates, 
			vector<int> tmp, vector<vector<int> >& res, int sum, int target, int beg) {
		// cout << "call one trace_combinationsum" << endl;
		for (int i = beg; i < candidates.size(); i++) {
			// cout << "tmparr is : ";
			// for (int j = 0; j < tmp.size(); j++) {
            //     cout << tmp[j] << " ";
            // }
			sum += candidates[i];
			// cout << "sum is " << sum << endl;
			// cout << endl;
			// cout << "candidates[i] : " << candidates[i] << endl;
			if (sum == target) {
				tmp.push_back(candidates[i]);  
				res.push_back(tmp);
				tmp.pop_back();
            } else if (sum < target) {
				tmp.push_back(candidates[i]);
				trace_combinationsum(candidates, tmp, res, sum, target, i);
				tmp.pop_back();
			} else {
				break;
			}
			sum -= candidates[i];
		}
		// cout << "end one trace_combinationsum\n" << endl;
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
	vp.push_back(make_pair<vector<int>,int>({1,2}, 2));
	vp.push_back(make_pair<vector<int>,int>({1,7}, 7));
	vp.push_back(make_pair<vector<int>,int>({2,3,6,7}, 7));
	vp.push_back(make_pair<vector<int>,int>({2,3,5}, 8));
	vp.push_back(make_pair<vector<int>,int>({}, 1));
	vp.push_back(make_pair<vector<int>,int>({8,7,4,3}, 7));
	Solution s;
	vector<pair<vector<int>,int> >::iterator iter;
	for (iter = vp.begin();
			iter != vp.end(); iter++) {
		cout << "vector : ";
		print((*iter).first);
		cout << "to find : " << (*iter).second << " : " << endl;
		vector<vector<int> >	res = s.combinationSum((*iter).first, (*iter).second);
		cout << "The result is :" << endl;
		vector<vector<int> >::iterator viter;
		cout << "[" << endl;
		for (viter = res.begin(); viter != res.end(); viter++) {
			cout << "\t" << "[";
			for (vector<int>::iterator it = (*viter).begin(); it != (*viter).end(); it++) {
				cout << *it;
				cout << ((it == (*viter).end() - 1) ? "" : ",");
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;
	}
	return 0;
}
