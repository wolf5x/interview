// 25min, RE...
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
        if(head == NULL)
            return head;
        ListNode **now = &head;
        while(*now != NULL && (*now)->next != NULL) {
            if((*now)->val != (*now)->next->val) {
                now = &((*now)->next);
            } else {
                ListNode *next = (*now)->next;
                while(next != NULL && next->val == (*now)->val) 
                    next = next->next;
                while(*now != next) {
                    ListNode *t = (*now)->next;
                    delete *now;
                    *now = t;
                }
            }
        }
        return head;
    }
};

