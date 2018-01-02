#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string tmp, res;
        int maxsublen = 0;
        unordered_set<char> hs;
        for (int i = 0; i < s.length(); i++) {
            int j = i;
            do {
                if (hs.find(s[j]) != hs.end()) {
                    cout << "find" << s[j] << endl;
                    break;
                }
                tmp += s[j];
                hs.insert(s[j]);
                j++;
            } while (j < s.length());
            if (tmp.length() > maxsublen) {
                res = tmp;
                maxsublen = res.length();
            }
            tmp.clear();
            hs.clear();
        }
        return maxsublen;
    }       
};

int main(void)
{
    string s = "pwwkew";
    Solution s1;
    int maxsublen = s1.lengthOfLongestSubstring(s);
    cout << maxsublen << endl;
    return(0);
}
