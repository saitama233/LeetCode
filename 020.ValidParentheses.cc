#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class solution {
public:
    bool isvalid(string s) {
        stack<char> sc;
        unordered_map<char, char> hm({{'}','{'}, {']', '['}, {')', '('}});

        // 这个#用的很巧妙，不需要判断sc.empty()，否则直接sc.top()会段错误
        sc.push('#');
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
            if (*iter == '{' || *iter == '[' || *iter == '(') {
                sc.push(*iter);
            } else if (*iter == '}' || *iter == ']' || *iter == ')') {
                if (hm[*iter] == sc.top())
                    sc.pop();
                else
                    return false;
            }
        }
        return sc.top() == '#' ? true : false;
    }
};

int main()
{
    solution s;
    string str;
    while (1) {
        cout << "Input a string:(ctrl+c to quit)" << endl;
        cin >> str;
        cout << (s.isvalid(str) ? "true" : "false") << endl;
    }
}
