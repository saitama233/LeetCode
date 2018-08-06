#include <iostream>
#include <string>
#include <stack>
using namespace std;

class solution {
public:
    bool isvalid(string s) {
        stack<char> sc;
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
            if (*iter == '{' || *iter == '[' || *iter == '(') {
                sc.push(*iter);
            } else if ((*iter == '}' && sc.top() == '{')
                    || (*iter == ']' && sc.top() == '[') 
                    || (*iter == ')' && sc.top() == '(')) {
                sc.pop();
            }
        }
        return sc.empty() ? true : false;
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
