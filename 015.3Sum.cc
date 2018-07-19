#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

class solution1 {
public:
    vector<vector<int> > threesum(vector<int>& nums) {
        vector<int> veci;
        unordered_map<int, vector<int> > hm;
        vector<vector<int> > vveci;
        unordered_set<int> hs;
        int small, middle, big;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                veci.clear();
                int tmp = 0 - nums[i] - nums[j];
                // 这里一定要用nums[i] <= nums[j]，否则i和j相等会出错
                if (nums[i] <= nums[j] && nums[i] <= tmp) {
                    small = nums[i];
                    middle = nums[j] < tmp ? nums[j] : tmp;
                } else if (nums[j] < nums[i] && nums[j] < tmp) {
                    small = nums[j];
                    middle = nums[i] < tmp ? nums[i] : tmp;
                } else {
                    small = tmp;
                    middle = nums[i] < nums[j] ? nums[i] : nums[j];
                }
                big = 0 - small - middle;
                // cout << small << " " << middle << " " << big << endl;
                // 为了下一个for的push_back得以正确排序，
                // 这里应该为hash[big] = [small, middle]
                veci.push_back(small);
                veci.push_back(middle);
                hm[big] = veci;
            }
        }
        // cout << endl;
        for (unordered_map<int, vector<int> >::iterator i = hm.begin(); 
                i != hm.end(); i++) {
            cout << (i->second)[0] << " " << (i->second)[1] << " "
                 << i->first << endl;
        }
        for (int i = 0; i < nums.size(); i++) {
            hs.insert(nums[i]);
        }
        /* for (unordered_set<int>::iterator i = hs.begin();
                i != hs.end(); i++) {
            cout << *i << " ";
        }
        cout << endl; */
        for (unordered_map<int, vector<int> >::iterator i = hm.begin(); 
                i != hm.end(); i++) {
            cout << "i->first: " << i->first << endl;
            if (hs.find(i->first) != hs.end()) {
                vector<int> tmp = i->second;
                tmp.push_back(i->first);
                vveci.push_back(tmp);
            }
        }
        cout << endl;
        return vveci;
    }
};

int main(void)
{
    int size;
    vector<int> veci;
    vector<vector<int> > vveci;
    solution1 s;

    srand(time(0));
    cout << "Input the size of the array: ";
    cin >> size;
    veci.clear();
    for (int i = 0; i < size; i++) {
        veci.push_back((rand()-rand())%5);
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << veci[i] << " ";
    }
    cout << endl;
    vveci = s.threesum(veci);
    cout << "[" << endl;
    for (int i = 0; i < vveci.size(); i++) {
        cout << "[";
        for (int j = 0; j < vveci[i].size(); j++) {
            cout << vveci[i][j];
            cout << (j == vveci[i].size()-1 ? "" : ", ");
        }
        cout << (i == vveci.size()-1 ? "]" : "],") << endl;
    }
    cout << "]" << endl;
    return 0;
}
