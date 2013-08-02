// 16min, 1RE
// 指针转移过程没想清楚
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode **pre = &head;
        while(true) {
            int cnt = 0;
            ListNode **tail = pre;
            while(*tail != NULL && cnt < k) {
                cnt++;
                tail = &((*tail)->next);
            }
            if(cnt < k) {
                break;
            }
            pre = reverseList(pre, tail);
        }
        return head;
    }
    
    ListNode **reverseList(ListNode **pre, ListNode **tail) {
        ListNode **new_tail = &((*pre)->next);
        while(&((*pre)->next) != tail) {
            ListNode *first = *pre;
            *pre = first->next;
            first->next = *tail;
            *tail = first;
        }
        return new_tail;
    }
};

