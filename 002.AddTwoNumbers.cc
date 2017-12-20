#include <iostream>
#include <cmath>
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

ListNode* numtolist(int num)
{
    cout << "in numtolist: " << num << endl;
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

void print_list(ListNode *l)
{
    ListNode *tmp = l;
    do {
        cout << tmp->val << (tmp->next ? " -> " : "\n");
    } while (tmp = tmp->next);
}

int main(void) 
{
    Solution1 s;
    ListNode *l1 = numtolist(456);
    print_list(l1);
    ListNode *l2 = numtolist(789);
    print_list(l2);
    ListNode *l3 = s.addTwoNumbers(l1, l2);
    print_list(l3);
    return(0);
}
