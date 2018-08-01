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
    List(int val);
    void createlist();
    void display();
};

List::List(int val) {
    head = new ListNode(val);
    head->next = NULL;
}

void List::createlist() {
    ListNode *p = head;
    ListNode *tmp;
    int size;
    cout << "Please input the size: " << endl;
    cin >> size;
    for (int i = 1; i < size; i++) {
        tmp = new ListNode(rand()%100);
        p->next = tmp;
        p = p->next;
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int i;
        ListNode *pre, *cur;
        ListNode *fast, *slow;
        fast = slow = head;
        for (i = 0; i < n && fast->next; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        pre = slow;
        if (pre->next && i == n) {
            cur = slow->next;
            pre->next = cur->next;
        } else {
            cur = pre;
            head = pre->next;
        }
        delete cur;
        return head;
    }
};

int main(void)
{
    solution s;
    int num;

    srand(time(0));
    List list(rand()%100);
    list.createlist();
    list.display();

    cout << "Input the num you want to delete:";
    cin >> num;
    s.removeNthFromEnd(list.head, num);
    list.display();

    return 0;
}
