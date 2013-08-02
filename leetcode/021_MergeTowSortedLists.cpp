// 6min, 1AC
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, **now = &head;
        while(l1 != NULL || l2 != NULL) {
            ListNode **next;
            if(l1 == NULL) next = &l2;
            else if(l2 == NULL) next = &l1;
            else {
                next = l1->val < l2->val ? &l1 : &l2;
            }
            *now = *next;
            now = &((*next)->next);
            *next = (*next)->next;
        }
        return head;
    }
};

