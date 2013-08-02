// http://leetcode.com/onlinejudge#question_116
// Layer by layer from top to bottom. Within a layer, from left to right
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/**
 * You may assume that it is a perfect binary tree 
 * (ie, all leaves are at the same level, and every parent has two children).
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        for(TreeLinkNode *head = root; head != NULL; head = head->left) {
            for(TreeLinkNode *go = head; go != NULL; go = go->next) {
                if (go->left != NULL)
                    go->left->next = go->right;
                if (go->right != NULL && go->next != NULL)
                    go->right->next = go->next->left;
            }
        }
    }
};

