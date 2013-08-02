// http://leetcode.com/onlinejudge#question_106
// O(n), see problem 105
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        stack<TreeNode *> stk;
        TreeNode *ans = NULL;
        TreeNode **par = &ans;
        for(int i = inorder.size()-1, j = i; j >= 0; j--) {
            *par = new TreeNode(postorder[j]);
            stk.push(*par);
            par = &(stk.top()->right);
            while (!stk.empty() && inorder[i] == stk.top()->val) {
                par = &(stk.top()->left);
                stk.pop();
                i--;
            }
        }
        return ans;
    }
};

