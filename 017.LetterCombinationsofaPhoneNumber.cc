#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// wrong answer:2.5h
class solution1 {
public:
    vector<string> lettercombinations(string digits) {
        unordered_map<char, string> hm;
        vector<string> oldstr, newstr;
        init_hm(hm);
        for (int i = 0; i < digits.size(); i++) {
            oldstr = newstr;
            cout << "digits.size() = " << digits.size() << endl;
            int size = newstr.size();
            for (int j = 0; newstr.empty() || j < size; j++) {
                unordered_map<char, string>::iterator hi
                    = hm.find(digits[i]);
                cout << "hi->second = " << hi->second << endl;
                if (hi == hm.end()) {
                    cout << "not found" << " ";
                    continue;
                }
                for (int k = 0; k < hi->second.size(); k++) {
                    if (i == 0) {
                        newstr.push_back((hi->second).substr(k, 1));
                        cout << (hi->second).substr(k, 1) << endl;
                    } else {
                        newstr[j] += (hi->second).substr(k, 1);
                        cout << "newstr[j]: " << newstr[j] << endl;
                    }
                    if (k < hi->second.size()-1)
                        newstr.insert(newstr.end(), 
                                oldstr.begin(), oldstr.end());
                }
                cout << "after insert" << endl;
            }
        }
        return newstr;
    }
private:
    void init_hm(unordered_map<char, string> &hm) {
        hm['2'] = "abc";
        hm['3'] = "def";
        hm['4'] = "ghi";
        hm['5'] = "jkl";
        hm['6'] = "mno";
        hm['7'] = "pqrs";
        hm['8'] = "tuv";
        hm['9'] = "wxyz";
    }
};

int main(void)
{
    string str;
    vector<string> vs;
    solution1 s;
    while(1) {
        cout << "Input a string(Ctrl+c to quit)";
        cin >> str;
        vs = s.lettercombinations(str);
        for (vector<string>::iterator iter = vs.begin(); 
                iter != vs.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
