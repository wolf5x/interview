// http://leetcode.com/onlinejudge#question_112
// WA1: not leaf!
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
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum(root, sum, 0);
    }
    
    bool hasPathSum(TreeNode *root, int sum, int len) {
        if (root == NULL)
            return sum == 0 && len > 0;
        if (root->left != NULL || root->right != NULL) {
            return root->left != NULL && hasPathSum(root->left, sum - root->val, len)
                    || root->right != NULL && hasPathSum(root->right, sum - root->val, len);
        }
        return sum - root->val == 0;
    }
};

