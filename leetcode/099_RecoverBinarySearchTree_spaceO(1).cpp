// http://leetcode.com/onlinejudge#question_99
// ???min
// Threaded Binary Tree: use 2 pointers to do INORDER traversal on a binary tree.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *p1 = NULL, *p2 = NULL;
        TreeNode *pre = NULL, *now = root;
        while(now != NULL) {
            if(now->left != NULL) {
                TreeNode *thr = now->left;
                while(thr->right != NULL && thr->right != now)
                    thr = thr->right;
                if(thr->right == now) {
                    check(pre, now, p1, p2);
                    thr->right = NULL;
                    pre = now;
                    now = now->right;
                } else {
                    thr->right = now;
                    now = now->left;
                }
            } else {
                check(pre, now, p1, p2);
                pre = now;
                now = now->right;
            }
        }
        swap(p1->val, p2->val);
    }
   
    void check(TreeNode *pre, TreeNode *now, TreeNode *&p1, TreeNode *&p2) {
        if (pre == NULL)
            return;
        if (pre->val >= now->val) {
            if (p1 == NULL)
                p1 = pre;
            p2 = now;
        }
    }
};

