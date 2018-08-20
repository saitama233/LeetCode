#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 没有去写主函数，两次ac，2h
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        mklists(lists, 0, lists.size());
        if (lists.size())
            return lists[0];
        else
            return NULL;
    }
private:
    void mklists(vector<ListNode*> &lists, int beg, int end) {
        int mid = (beg + end) / 2;
        // 少于两个元素终止递归，
        if (beg + 1 >= end)
            return;
        mklists(lists, beg, mid);
        mklists(lists, mid, end);

        merge(lists, beg, mid);
    }
    void merge(vector<ListNode*> &lists, int beg, int mid) {
       // pre指向first前一个Node，
        ListNode *first, *second, *pre;
        if (!lists[mid])
            return;
        if (!lists[beg]) {
            lists[beg] = lists[mid];
            return;
        }
        pre = first = lists[beg];
        second = lists[mid];
        while (first && second) {
            if (first->val > second->val) {
                if (pre == first) { // 当first指向头结点的时候，
                    lists[beg] = pre = second;
                    second = second->next;
                    pre->next = first;
                } else {
					pre->next = second;
                    pre = second;
                    second = second->next;
                    pre->next = first;
                }
            } else {
                if (pre != first)
                    pre = pre->next;
                first = first->next;
            }
        }
        if (second)
            pre->next = second;
            
		/* cout << beg << " : ";
		for (first = lists[beg]; first != NULL; first = first->next) {
			cout << first->val << " ";
		}
		cout << endl; */
    } 
};

int main(void)
{
    return 0;
}
