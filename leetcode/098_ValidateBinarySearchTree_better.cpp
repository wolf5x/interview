// another approach
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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, false, 0, false, 0);
    }
    
    bool isValidBST(TreeNode *root, bool lbound, int lmax, bool rbound, int rmin) {
        if (root == NULL)
            return true;
        if(lbound && root->val >= lmax)
            return false;
        if(rbound && root->val <= rmin)
            return false;
        return isValidBST(root->left, true, root->val, rbound, rmin)
            && isValidBST(root->right, lbound, lmax, true, root->val);
    }
};

