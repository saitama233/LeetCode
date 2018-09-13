#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Approach 1: Recursion
class reg_exp1 {
public:
    bool ismatch(string p, string s)
    {
        bool flag;
        
        if (p.empty()) return s.empty();
        
        flag = p[0] == s[0] || p[0] == '.';

        if (p.size() > 1 && p[1] == '*') { // 有*的情况
            return ismatch(p.substr(2), s) || (flag && ismatch(p, s.substr(1)));
        } else { // 没有*的情况
            return flag && ismatch(p.substr(1), s.substr(1));
        }
    }
};

// Approach 2: Dynamic Programming
class reg_exp2 {
public:
    bool ismatch(string p, string s)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > 1 && p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || 
                        (i > 0 && dp[i-1][j] && 
                            (p[j-2] == s[i-1] || p[j-2] == '.'));
                } else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && 
                        (p[j-1] == s[i-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

int main(void)
{
    reg_exp2 re;
    string s, p;
    while (1) {
        cout << "Ctrl+c to quit!" << endl;
        cout << "input the string s:";
        cin >> s;
        cout << "input the pattern p:";
        cin >> p;

        if (re.ismatch(p, s)) {
            cout << p << " match the entire string " << s << endl; 
        } else {
            cout << p << " does not match the entire string " << s << endl;
        }
    }
    return 0;
}
