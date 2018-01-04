#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//最初始的解法，比较笨
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        string tmp, res;
        int maxsublen = 0;
        unordered_set<char> hs;
        //可以稍微优化下，把s.length()赋值给n，否则每次比较
        //都要调用length()函数
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

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        string::iterator i = s.begin(), j = s.begin();
        string res;
        unordered_set<char> hs;
        int len = s.length();
        int maxsublen = 0;
        while (j < s.end()) {
            if (hs.find(*j) != hs.end()) {
                hs.erase(hs.find(*i));
                i++;
            } else {
                hs.insert(*j);
                j++;
                if ((j - i) > maxsublen) {
                    maxsublen = j - i;
                    res.clear();
                    res.assign(i, j);
                }
            }
        }
        cout << res << endl;
    return res.length();
    }
};

int main(void)
{
    string s;
    Solution1 s1;
    Solution2 s2;
    cout << "请输入任意字符串：" << endl;
    cin >> s;
    int maxsublen = s2.lengthOfLongestSubstring(s);
    cout << maxsublen << endl;
    return(0);
}
