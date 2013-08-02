// http://leetcode.com/onlinejudge#question_113
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
    vector<vector<int> > ans;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> tmp;
        ans.clear();
        solve(tmp, root, sum);
        return ans;
    }
    
    void solve(vector<int> &now, TreeNode *root, int sum) {
        if (root == NULL)
            return;
        now.push_back(root->val);
        int rest = sum - root->val;
        if (root->left != NULL)
            solve(now, root->left, rest);
        if (root->right != NULL) 
            solve(now, root->right, rest);
        if (root->left == NULL && root->right == NULL && rest == 0)
            ans.push_back(now);
        now.pop_back();
    }
    
};

