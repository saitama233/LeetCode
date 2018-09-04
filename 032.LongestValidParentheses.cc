#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 网上看的答案，动态规划，2h
class Solution {
public:
    int longestValidParentheses(string s) {
		int max = 0;
		int *dp = NULL;
		dp = new int[s.length()]();
		for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                int j = i - 1 - dp[i-1];
                if (j >= 0 && s[j] == '(')
                    dp[i] = dp[i-1] + 2;
                if (j-1 > 0)
                    dp[i] += dp[j-1];
                if (dp[i] > max)
                    max = dp[i];
            }
		}
        return max; 
    }
};

int main()
{
	vector<string> vs;
    Solution s;
	vs.push_back(")()()(");			// 4
	vs.push_back("");               // 0
	vs.push_back("((");             // 0
	vs.push_back(")(())()(");       // 6
	vs.push_back("()");				// 2
	for (vector<string>::iterator vi = vs.begin(); 
			vi != vs.end(); vi++) {
		cout << *vi << ": " << s.longestValidParentheses(*vi) << endl;
	}
	return 0;
}
