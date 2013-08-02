// 30min
// 递推 (recursion is better)
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
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *> > tbl(n+1);
        tbl[0].push_back(NULL);
        for(int m = 1; m <= n; m++) {
            for(int k = 1; k <= m; k++) {
                for(int i = 0; i < tbl[k-1].size(); i++) {
                    for(int j = 0; j < tbl[m-k].size(); j++) {
                        TreeNode *root = new TreeNode(k);
                        copy(tbl[k-1][i], root->left, 0);
                        copy(tbl[m-k][j], root->right, k);
                        tbl[m].push_back(root);
                    }
                }
            }
        }
        return tbl[n];
    }
    
    void copy(TreeNode *&src, TreeNode *&des, int det) {
        if (src == NULL)
            return;
        des = new TreeNode(src->val + det);
        copy(src->left, des->left, det);
        copy(src->right, des->right, det);
    }
};

