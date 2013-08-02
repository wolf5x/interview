// 5min
// dfs
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
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode *root, int acc) {
        if(root == NULL)
            return 0;
        acc += root->val;
        if(root->left == NULL && root->right == NULL) 
            return acc;
        return sumNumbers(root->left, acc*10) 
                + sumNumbers(root->right, acc*10);
    }
};

