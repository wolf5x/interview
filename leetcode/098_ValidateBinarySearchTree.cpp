// 20min
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
        int lo, hi;
        return isValidBST(root, lo, hi);
    }
    
    bool isValidBST(TreeNode *root, int &lo, int &hi) {
        if (root == NULL)
            return true;
        lo = hi = root->val;
        int myLo = 1, myHi = -1;
        if(!isValidBST(root->left, myLo, myHi))
            return false;
        if(myLo <= myHi) {
            if (myHi >= lo)
                return false;
            lo = myLo;
        }
        myLo = 1, myHi = -1;
        if(!isValidBST(root->right, myLo, myHi))
            return false;
        if(myLo <= myHi) {
            if (myLo <= hi)
                return false;
            hi = myHi;
        }
        return true;
    }
};

