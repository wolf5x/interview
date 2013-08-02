// 15min, 1RE
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
    ListNode *rotateRight(ListNode *head, int k) {
        int n = 0;
        ListNode **tail = &head;
        while(*tail != NULL) {
            tail = &((*tail)->next);
            n++;
        }
        if (n == 0) // RE: miss here.
            return head;
        k = (n-k%n)%n;
        ListNode **now = &head;
        while(k-- > 0) {
            *tail = *now;
            *now = (*now)->next;
            (*tail)->next = NULL;
            tail = &((*tail)->next);
        }
        return head;
    }
};

