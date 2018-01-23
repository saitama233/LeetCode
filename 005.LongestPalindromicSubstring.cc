#include <iostream>
#include <string>
using namespace std;

bool ispalindromic(string::iterator begin, string::iterator end)
{
    for (int i = 0; begin+i < end-i-1; i++) {
        if (*(begin+i) != *(end-i-1))
            return(0);
    }
    return(1);
}

class Solution1 {
public:
    string longestPalindrome(string s) {
        string::iterator begin, end, b, e;
        if (s.size() == 1)
            return s;
        begin = s.begin();
        end = s.begin() + 1;
        for (b = s.begin(); s.end() - b > end - begin; b++) {
            e = s.end();
            while (e - b > end - begin) {
                if (ispalindromic(b, e)) {
                    begin = b;
                    end = e;
                    break;
                } else {
                    e--;
                }
            }
        }
        return(string(begin, end));
    }
};

int main(void)
{
    Solution1 s1;
    string s, substr;
    cout << "请输入字符串：" << endl;
    cin >> s;
    substr = s1.longestPalindrome(s);
    cout << "最长回文为：" << substr << endl;
    return(0);
}
