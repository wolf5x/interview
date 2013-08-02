// http://leetcode.com/onlinejudge#question_110
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
    bool isBalanced(TreeNode *root) {
        int h = getHeight(root);
        return h >= 0;
    }
    
    int getHeight(TreeNode *root) {
        if (root == NULL)
            return 0;
        int lh = getHeight(root->left);
        if (lh < 0)
            return -1;
        int rh = getHeight(root->right);
        if (rh < 0)
            return -1;
        if(lh+1 < rh || rh+1 < lh)
            return -1;
        return max(lh, rh)+1;
    }
};

