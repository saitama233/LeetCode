/*
 * 76. Minimum Window Substring
 * Hard
 *
 * Given a string S and a string T,
 * find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * Note:
 *
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 * Accepted 203,504
 * Submissions 689,782
 */

/* 用时5h，错误的答案，逻辑有问题 */
class Solution1 {
public:
    string minWindow(string s, string t) {
        unordered_multiset<char> tset;
        unordered_multiset<char>::iterator titer;
        queue<pair<char, string::iterator>> qc;
        string::iterator iter, first = s.begin(), last = s.begin();
        int min = 0;
        
        for (int i = 0; i < t.size(); i++) {
            tset.insert(t[i]);
        }
        for (iter = s.begin(); iter < s.end(); iter++) {
            if (!tset.empty()) {
                if ((titer = tset.find(*iter)) != tset.end()) {
                    qc.push(make_pair(*iter, iter));
                    tset.erase(titer);
                }
            } else {
                first = qc.empty() ? iter : qc.front().second;
                last = iter;
                min = last - first;
                break;
            }
        }
        if (t.size() < 1 || (t.size() == 1 && !min))
            return t;
        for (int i = 0; i < t.size(); i++) {
            tset.insert(t[i]);
        }
        for (; iter < s.end(); iter++) {
            if (!qc.empty() && qc.front().first == *iter && min) {
                qc.pop();
                if (iter + 1 - qc.front().second < min) {
                    first = qc.front().second;
                    last = iter + 1;
                    min = last - first;
                }
                qc.push(make_pair(*iter, iter));
            }
        }
        return string(first, last);
    }
};

/*
 * 将s中的所有字符都存入数组，数组的每个元素是一个queue，queue的每个元素都存储当前字符，当前字符位置，下一个字符位置，
 * （ums1只存储同时在s和t中存在的字符）
 * 需要存储first的值，
 */
/* 用时3h，还是不对 */
class Solution2 {
public:
    string minWindow(string s, string t) {
        queue<pair<char, pair<string::iterator, string::iterator>>> q[256]; /* queue的char可以删除 */
        unordered_multiset<char> tumset;
        unordered_multiset<char>::iterator titer;
        string::iterator iter, first = s.end(), last = s.begin();
        stack<pair<char, pair<string::iterator, string::iterator>>> pre;
        int min = 0;
        
        for (int i = 0; i < t.size(); i++) {
            tumset.insert(t[i]);
        }
        for (iter = s.begin(); iter < s.end(); iter++) {
            if (!tumset.empty()) {
                if ((titer = tumset.find(*iter)) != tumset.end()) {
                    if (iter < first) {
                        first = iter;
                    }
                    if (!pre.empty()) {
                        q[pre.top().first].front().second.second = iter;
                        cout << "q[pre.top().first].front().second.second: "
                             << q[pre.top().first].front().second.second -s.begin() << endl;
                        cout << "pre.top().first: " << pre.top().first << endl;
                        pre.pop();
                    }
                    q[*iter].push(make_pair(*iter, make_pair(iter, s.end())));
                    pre.push(make_pair(*iter, make_pair(iter, s.end())));
                    tumset.erase(titer);
                }
            } else {
                /* first = pre.empty() ? iter : pre.top().second.first; */
                last = iter;
                cout << "last - s.begin(): " << last - s.begin() << endl;
                min = last - first;
                cout << "min: " << min << endl;
                break;
            }
        }
        if (t.size() < 1 || (t.size() == 1 && !min))
            return t;
        for (; iter < s.end(); iter++) {
            if (!(q[*iter].empty()) && min) {
                if (!pre.empty()) {
                    q[pre.top().first].front().second.second = iter;
                    cout << "q[pre.top().first].front().second.second: "
                         << q[pre.top().first].front().second.second - s.begin() << endl;
                    cout << "pre.top().first: " << pre.top().first << endl;
                    pre.pop();
                }
                if (first == q[*iter].front().second.first) {
                    first = q[*iter].front().second.second;
                    cout << "first - s.begin(): " << first - s.begin() << endl;
                } else {
                    q[*(q[*iter].front().first)].front = 
                }
                q[*iter].pop();
                if (iter + 1 - first < min) {
                    /* first = first; */
                    last = iter + 1;
                    min = last - first;
                }
                cout << "*iter: " << *iter << endl;
                q[*iter].push(make_pair(*iter, make_pair(iter, s.end())));
                pre.push(make_pair(*iter, make_pair(iter, s.end())));
            }
        }
        return string(first, last);
    }
};

/*
 * 可以把所有符合的元素依次添加进一个list双向链表，每个list的元素是（当前字符，当前字符位置），
 * 再维护一个数组，每个元素都是一个queue，queue的元素是该元素在list中的位置，
 */
/* 用时2h，3次AC，虽然算法的效率和空间利用都很差，写的也很乱，
 * 不过能做出来已经很不容易了，独立做出来的第三道hard类型的题，这一道做的特别吃力，共用时10h，
 * Runtime: 44 ms, faster than 14.10% of C++ online submissions for Minimum Window Substring.
 * Memory Usage: 2.2 MB, less than 1.25% of C++ online submissions for Minimum Window Substring.
 */
class Solution {
public:
    string minWindow(string s, string t) {
        list<pair<char, string::iterator>> l;
        list<pair<char, string::iterator>>::iterator list_idx;
        queue<list<pair<char, string::iterator>>::iterator> ql[256];
        unordered_multiset<char> tumset;
        unordered_multiset<char>::iterator titer;
        string::iterator iter, first = s.begin(), last = s.begin();
        int min = 0;

        for (int i = 0; i < t.size(); i++) {
            tumset.insert(t[i]);
        }
        for (iter = s.begin(); iter < s.end(); iter++) {
            if (!tumset.empty()) {
                if ((titer = tumset.find(*iter)) != tumset.end()) {
                    list_idx = l.insert(l.end(), make_pair(*iter, iter));
                    ql[*iter].push(list_idx);
                    tumset.erase(titer);
                    cout << *iter << endl;
                } else if (ql[*iter].size()) {
                    l.erase(ql[*iter].front());
                    ql[*iter].pop();
                    if (iter + 1 - l.begin()->second < min) {
                        first = l.begin()->second;
                        last = iter + 1;
                        min = last - first;
                    }
                    list_idx = l.insert(l.end(), make_pair(*iter, iter));
                    ql[*iter].push(list_idx);
                }
            } else {
                break;
            }
        }
        if (tumset.empty()) {
            first = l.empty() ? iter : l.begin()->second;
            last = iter;
            cout << "first - s.begin(): " << first - s.begin() << endl;
            cout << "last - s.begin(): " << last - s.begin() << endl;
            min = last - first;
            /* cout << "min: " << min << endl; */
        }
        /* 当s比t长很多且s并没有包含t时可以提高些速度，避免进入下面的循环判断 */
        /* if (t.size() < 1 || (t.size() == 1 && !min)) */
            /* return string(); */
        for (; iter < s.end(); iter++) {
            if (!(ql[*iter].empty()) && min) {
                l.erase(ql[*iter].front());
                ql[*iter].pop();
                if (iter + 1 - l.begin()->second < min) {
                    first = l.begin()->second;
                    last = iter + 1;
                    min = last - first;
                }
                /* cout << "*iter: " << *iter << endl; */
                list_idx = l.insert(l.end(), make_pair(*iter, iter));
                ql[*iter].push(list_idx);
            }
        }
        return string(first, last);
    }
};

int main()
{
    return 0;
}