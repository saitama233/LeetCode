#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 错误的方法：1h
class solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        string str(n * 2, '*');
        int flag = 0;
        int left, right;
        char pair[2] = {'(', ')'};
        
        left = right = n;
        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0 && left > 0) {
                    left--;
                    flag++;
                }
                else if (j == 1 && right > 0) {
                    right--;
                    flag--;
                    if (flag < 0)
                        break;
                }
                str[i] = pair[j];

                if (left == 0 && right == 0) {
                    vs.push_back(str);
                }
            }
        }

        return vs;
    }
};

int main(void)
{
    solution1 s;
    int num;
    vector<string> vs;

    while (1) {
        cout << "Please input the num:" << endl;
        cin >> num;
        vs = s.generateParenthesis(num);
        cout << '[' << endl;
        for (vector<string>::iterator iter = vs.begin();
                iter != vs.end(); iter++) {
            cout << *iter << (iter != vs.end()-1 ? "," : "") << endl;
        }
        cout << ']' << endl;
    }

    return 0;
}
