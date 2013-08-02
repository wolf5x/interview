// http://leetcode.com/onlinejudge#question_111
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
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        return 1+(lh == 0 ? rh : rh == 0 ? lh : min(lh, rh));
    }
};

