/**
 * Given a linked list: n1->n2->...->n100,
 * transform it to n1->n3->..->n99->n100->n98->..->n2.
 */

//---------- Header --------------
#include <iostream>
using namespace std;

struct ListNode {
    ListNode *next;
    int val;
    ListNode(int _val, ListNode *_next) : val(_val), next(_next){}
    ~ListNode(){ delete next; }
};

//---------- Solution ------------
 
class Solution {
public:
    ListNode *solve(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *tail = NULL;
        ListNode **now = &(head->next);
        while (*now != NULL && (*now)->next != NULL) {
            ListNode *move = *now;
            *now = move->next;
            move->next = tail;
            tail = move;
            now = &((*now)->next);
        }
        if (*now == NULL)
            *now = tail;
        else
            (*now)->next = tail;
        return head;
    }
};

//---------- Checker -------------

class Checker {
public:
    void showList(ListNode *head) {
        while(head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << '\n';
    }

    void testOne(ListNode *head) {
        showList(Solution().solve(head));
    }

    void check() {
        testOne(NULL);
        testOne(new ListNode(0, NULL));
        testOne(new ListNode(0, new ListNode(1, NULL)));
        testOne(new ListNode(0, new ListNode(1, new ListNode(2, NULL))));
        testOne(new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, NULL)))))));
        testOne(new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, NULL))))))));
    }
};

int main() {
    Checker().check();
    return 0;
}


