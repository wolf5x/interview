// http://leetcode.com/onlinejudge#question_101
// recursively
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
    bool isSymmetric(TreeNode *root) {
        return root == NULL ? true : isSymmetric(root->left, root->right);
    }
   
    bool isSymmetric(TreeNode *lroot, TreeNode *rroot) {
        if (lroot == NULL && rroot == NULL) {
            return true;
        } else if (lroot != NULL && rroot != NULL) {
            return lroot->val == rroot->val
                    && isSymmetric(lroot->left, rroot->right)
                    && isSymmetric(lroot->right, rroot->left);
        } else {
            return false;
        }
    }
};

