// 15min, 1WA: <0
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
    int maxPathSum(TreeNode *root) {
        int len;
        return getdp(root, len);
    }
    
    int getdp(TreeNode *root, int &len) {
        len = INT_MIN;
        if (root == NULL)
            return INT_MIN;
        int dl, dr;
        int ret = max(getdp(root->left, dl), getdp(root->right, dr));
        ret = max(ret, root->val + (dl<0?0:dl) + (dr<0?0:dr));
        len = max(0,max(dl,dr)) + root->val;
        return ret;
    }
};

