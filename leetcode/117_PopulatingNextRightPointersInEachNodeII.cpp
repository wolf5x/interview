// http://leetcode.com/onlinejudge#question_117
// 20min, 2RE..
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        for (TreeLinkNode *head = root, *next_head; head != NULL; head = next_head) {
            TreeLinkNode *pre = NULL;
            next_head = NULL; // 1st RE: *next_head
            for (TreeLinkNode *go = head; go != NULL; go = go->next) {
                if (doConnect(pre, go->left) && next_head == NULL)
                    next_head = pre;
                if (doConnect(pre, go->right) && next_head == NULL)
                    next_head = pre;
            }
        }
    }
    
    bool doConnect(TreeLinkNode *&pre, TreeLinkNode *next) {
        if (next == NULL)
            return false;
        if (pre != NULL) // 2nd RE: NULL!
            pre->next = next;
        pre = next;
        return true;
    }
};

