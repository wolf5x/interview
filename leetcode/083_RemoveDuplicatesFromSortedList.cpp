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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *now = head, *next;
        if (now == NULL)
            return head;
        next = now->next;
        while(next != NULL) {
            if(now->val != next->val) {
                now->next = next;
                now = now->next;
                next = next->next;
            } else {
                ListNode *t = next->next;
                delete next;
                next = t;
            }
        }
        now->next = NULL;
        return head;
    }
};

