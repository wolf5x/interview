// http://leetcode.com/onlinejudge#question_102
// 5min
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        vector<TreeNode *> lay[2];
        lay[0].push_back(root);
        for(int s = 0; !lay[s].empty(); s ^= 1) {
            vector<TreeNode *> &now = lay[s], &next = lay[s^1];
            next.clear();
            vector<int> tmp;
            for(int i = 0; i < now.size(); i++) {
                if (now[i] != NULL) {
                    tmp.push_back(now[i]->val);
                    next.push_back(now[i]->left);
                    next.push_back(now[i]->right);
                }
            }
            if (!tmp.empty())
                ans.push_back(tmp);
        }
        return ans;
    }
};

