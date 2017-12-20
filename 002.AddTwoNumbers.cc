#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct ListNode {
    int         val;
    ListNode    *next;
    ListNode(int x): val(x), next(NULL) {}
};
void print_list(ListNode *l);

//最开始写的，错误的解法（没有考虑大数相加）
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int tmp, sum = 0, ix = 0;
        ListNode *head = NULL, *tail = NULL, *cur = NULL;
        cur = l1;
        while (cur) {
            sum += cur->val * static_cast<int>(pow(10, ix));
            cur = cur->next;
            ix++;
        }
        cout << "sum1 is :" << sum << endl;
        ix = 0;
        cur = l2;
        while (cur) {
            sum += cur->val * static_cast<int>(pow(10, ix));
            cur = cur->next;
            ix++;
        }
        cout << "sum2 is :" << sum << endl;
        tmp = sum;
        //下面也可以使用numtolist函数
        //不过使用numtolist不对，还是运算不了大数相加
        do {
            cur = new ListNode(tmp%10);
            cur->next = NULL;
            if (head == NULL) {
                head = tail = cur;
            } else {
                tail->next = cur;
                tail = cur;
            }
        } while (tmp /= 10);
        return head;
    }
};

//经过修改的解法，可以进行大数相加，不过比较繁琐，没有优化
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp, sum = 0, ix1 = 0, ix2 = 0;
        ListNode *head = NULL, *tail = NULL;
        ListNode *cur1 = l1, *cur2 = l2, *cur = NULL;
        int up = 0; //这个换成carry比较好
        do {
            sum = 0;
            if (cur1) {
                sum += cur1->val;
                cur1 = cur1->next;
                ix1++;
            }
            if (cur2) {
                sum += cur2->val;
                cur2 = cur2->next;
                ix2++;
            }
            sum += up;
            if (sum >= 10) {
                up = 1;
            } else {
                up = 0;
            }
            cur = new ListNode(sum%10);
            cur->next = NULL;
            if (head == NULL) {
                head = tail = cur;
            } else {
                tail->next = cur;
                tail = cur;
            }
        } while (cur1 || cur2);
        if (up) {
            cur = new ListNode(1);
            tail->next = cur;
            tail = cur;
        }
        return head;
    }
};

/*
因为参数是int，无法存储大数，所以不能使用这个，用下面的stringtolist替换
ListNode* numtolist(int num)
{
    ListNode *head = NULL, *tail = NULL, *cur = NULL;
    int tmp = num;
    //数字肯定是需要运行一次的,即使是0，所以用do-while好点
    do {
        cur = new ListNode(tmp%10);
        cur->next = NULL;
        if (head == NULL) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    } while (tmp /= 10);
    return head;
}
*/
ListNode* stringtolist(string s)
{
    ListNode *head = NULL, *tail = NULL, *cur = NULL;
    int ix = 0;
    //数字肯定是需要运行一次的,即使是0，所以用do-while好点
    do {
        cur = new ListNode(s[ix]-48);
        cur->next = NULL;
        cout << "cur->val: " << cur->val << endl;
        if (head == NULL) {
            head = tail = cur;
        } else {
            cur->next = head;
            head = cur;
        }
    } while (s[++ix]);
    return head;
}

void print_list(ListNode *l)
{
    ListNode *tmp = l;
    do {
        cout << tmp->val << (tmp->next ? " -> " : "\n");
    } while (tmp = tmp->next);
}

int main(void)
{
    Solution2 s;
    string s1, s2;
    cout << "请输入s1:";
    cin >> s1;
    cout << "请输入s2:";
    cin >> s2;
    ListNode *l1 = stringtolist(s1);
    print_list(l1);
    ListNode *l2 = stringtolist(s2);
    print_list(l2);
    ListNode *l3 = s.addTwoNumbers(l1, l2);
    print_list(l3);
    return(0);
}
