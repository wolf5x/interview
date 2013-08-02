// 30min, stucked...
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
    ListNode *partition(ListNode *head, int x) {
        ListNode **now = &head, **next;
        while(*now != NULL && (*now)->val < x)
            now = &((*now)->next);
        next = now;
        while(*next != NULL) {
            if((*next)->val >= x)
                next = &((*next)->next);
            else {
                ListNode *mv = *next;
                *next = mv->next;
                mv->next = *now;
                *now = mv;
                now = &((*now)->next);
            }
        }
        return head;
    }
};

