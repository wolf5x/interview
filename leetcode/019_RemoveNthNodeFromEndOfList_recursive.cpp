/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        remove(head, n);
        return head;
    }
    
    int remove(ListNode *&pre, int n) {
        if(pre == NULL) {
            return 0;
        }
        ListNode *now = pre;
        int idx = 1+remove(now->next, n);
        if(idx == n) {
            pre = now->next;
            delete now;
        }
        return idx;
    }
};

