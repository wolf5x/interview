// 19min, 2CE
// in-place merge
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        set<pair<int, ListNode*>> heap;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                heap.insert(make_pair(lists[i]->val, lists[i]));
            }
        }
        ListNode *head = NULL, **pointer = &head;
        while(!heap.empty()) {
            ListNode *now = heap.begin()->second;
            heap.erase(heap.begin());
            *pointer = now;
            pointer = &(now->next);
            if (*pointer != NULL) {
                heap.insert(make_pair((*pointer)->val, *pointer));
            }
        }
        *pointer = NULL;
        return head;
    }
};

