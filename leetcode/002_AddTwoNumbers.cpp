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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = NULL, **p = &ans;
        int carry = 0;
        while(carry != 0 || l1 != NULL || l2 != NULL) {
            int x = carry;
            if (l1 != NULL) 
                x += l1->val, l1 = l1->next;
            if (l2 != NULL)
                x += l2->val, l2 = l2->next;
            if(x > 9)
                carry = 1, x -= 10;
            else 
                carry = 0;
            *p = new ListNode(x);
            p = &((*p)->next);
        }
        return ans;
    }
};

