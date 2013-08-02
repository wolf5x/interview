// 1hour??..
// O(n), iteratively. The YY works... but not proved yet...
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
         stack<TreeNode *> stk;
         TreeNode *ans = NULL;
         TreeNode **par = &ans;
         for(int i = 0, j = 0; i < preorder.size(); i++) {
             *par = new TreeNode(preorder[i]);
             stk.push(*par);
             par = &((*par)->left);
             while(!stk.empty() && inorder[j] == stk.top()->val) {
                 par = &(stk.top()->right);
                 stk.pop();
                 j++;
             }
         }
         return ans;
    }
};

