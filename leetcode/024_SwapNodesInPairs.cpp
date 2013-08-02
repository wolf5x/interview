// 12min, 1Y
// two additional pointers
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
    ListNode *swapPairs(ListNode *head) {
        ListNode **pre = &head;
        while(*pre != NULL 
                && (*pre)->next != NULL) {
            ListNode *first = *pre;
            *pre = first->next;
            first->next = (*pre)->next;
            (*pre)->next = first;
            pre = &(first->next);
        }
        return head;
    }
};

