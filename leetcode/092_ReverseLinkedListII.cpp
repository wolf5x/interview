// 10min
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode **now = &head;
        for(int i = 0; i < m-1; i++) {
            now = &((*now)->next);
        }
        ListNode *tail = *now;
        for(int i = 0; i < n-m; i++) {
            ListNode *mv = tail->next;
            tail->next = mv->next;
            mv->next = *now;
            *now = mv;
        }
        return head;
    }
};

