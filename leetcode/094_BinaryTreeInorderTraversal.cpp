// 30min
// TODO preorder, postorder ? 
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *now = root;
        while(now != NULL || !stk.empty()) {
            if(now != NULL) {
                stk.push(now);
                now = now->left;
            } else {
                now = stk.top();
                stk.pop();
                if(now != NULL) {
                    ans.push_back(now->val);
                    now = now->right;
                }
            }
        }
        return ans;
    }
};

