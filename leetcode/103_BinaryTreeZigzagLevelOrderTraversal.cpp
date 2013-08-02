// http://leetcode.com/onlinejudge#question_103
// 8min, WA1 @ left,right
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        vector<TreeNode *> lay[2];
        lay[0].push_back(root);
        for(int s = 0; !lay[s].empty(); s ^= 1) {
            vector<TreeNode *> &now = lay[s], &next = lay[s^1];
            next.clear();
            vector<int> tmp;
            for(int i = now.size()-1; i >= 0; i--) {
                if (now[i] != NULL) {
                    tmp.push_back(now[i]->val);
                    if (!s) {
                        next.push_back(now[i]->left);
                        next.push_back(now[i]->right);
                    } else { // WA: missed here
                        next.push_back(now[i]->right);
                        next.push_back(now[i]->left);
                    }
                }
            }
            if (!tmp.empty())
                ans.push_back(tmp);
        }
        return ans;
    }
};

