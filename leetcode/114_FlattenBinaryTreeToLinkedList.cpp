// http://leetcode.com/onlinejudge#question_114
// 15min
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
    void flatten(TreeNode *root) {
        flatten(root, NULL);
    }
    
    TreeNode *flatten(TreeNode *root, TreeNode *next) {
        if (root == NULL)
            return next;
        next = flatten(root->right, next);
        next = flatten(root->left, next);
        root->left = NULL;
        root->right = next;
        return root;
    }
};

