#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class List {
public:
    ListNode *head;
    List();
    void createlist();
    void display();
};

List::List() {
    head = NULL;
}

void List::createlist() {
    ListNode *p = head;
    ListNode *tmp;
    int val;
    int size;
    while (1) {
        cout << "Input the value you want to insert(<0 to break)" << endl;
        cin >> val;
        if (val < 0)
            break;
        tmp = new ListNode(val);
        if (head) {
            p->next = tmp;
            p = p->next;
        } else {
            p = head = tmp;
        }
    }
}

void List::display() {
    ListNode *tmp = head;
    cout << "The list is: " << endl;
    while (tmp) {
        cout << tmp->val << ((tmp->next) ? "->" : "");
        tmp = tmp->next;
    }
    cout << endl;
}

class solution {
public:
    ListNode* mergetwolists(ListNode *l1, ListNode *l2) {
        ListNode *l = new ListNode(0);
        ListNode *p = l;
        ListNode *tmp;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tmp = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tmp = new ListNode(l2->val);
                l2 = l2->next;
            }
            p->next = tmp;
            p = p->next;
        }
        while (l1) {
            tmp = new ListNode(l1->val);
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            tmp = new ListNode(l2->val);
            p->next = tmp;
            p = p->next;
            l2 = l2->next;
        }

        return l->next;
    }
};

int main(void)
{
    solution s;
    ListNode *l, *tmp;

    List list1;
    list1.createlist();
    list1.display();

    List list2;
    list2.createlist();
    list2.display();
    
    l = s.mergetwolists(list1.head, list2.head);
    cout << "The list after merge:" << endl;
    tmp = l;
    while (tmp) {
        cout << tmp->val << (tmp->next ? "->" : "");
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}
