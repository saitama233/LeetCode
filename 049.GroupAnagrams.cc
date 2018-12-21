#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hmap;
        unordered_map<string, int>::iterator hm_iter;
        vector<vector<string>> res;
        string tmpstr;
        
        for (int i = 0; i < strs.size(); i++) {
            tmpstr = strs[i];
            sort(tmpstr.begin(), tmpstr.end());
            hm_iter = hmap.find(tmpstr);
            if (hm_iter != hmap.end()) {
                res[hm_iter->second].push_back(strs[i]);
            } else if (hm_iter == hmap.end()) {
                hmap.insert(make_pair(tmpstr, res.size()));
                res.push_back({});
                (res.end() - 1)->push_back(strs[i]);
            }
        }
        return res;
    }
};

void print(vector<vector<string>> &vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++) {
        cout << "{";
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            cout << (j + 1 == vec[i].size() ? "" : ",");
        }
        cout << "}";
        cout << (i + 1 == vec.size() ? "" : ",");
    }
    cout << "}" << endl;
}

int main()
{
    Solution1 s;
    
    vector<vector<string>> strs;
    strs.push_back({"eat","tea","tan","ate","nat","bat"});
    
    vector<vector<string>> res;
    
    for (int i = 0; i < strs.size(); i++) {
        res = s.groupAnagrams(strs[i]);
        print(res);
    }
    
    return 0;
}
