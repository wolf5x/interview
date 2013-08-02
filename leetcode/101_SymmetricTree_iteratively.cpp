// http://leetcode.com/onlinejudge#question_101
// iteratively: layer by layer
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
    bool isSymmetric(TreeNode *root) {
        vector<TreeNode *> layer[2];
        layer[0].push_back(root);
        for(int step = 0; !layer[step].empty(); step ^= 1) {
            vector<TreeNode *> &now = layer[step], &next = layer[step^1];
            next.clear();
            for(int i = 0; i < now.size(); i++) {
                if (now[i] != NULL) {
                    next.push_back(now[i]->left);
                    next.push_back(now[i]->right);
                }
            }
            for(int i = 0, j = next.size()-1; i < j; i++, j--) {
                if ((next[i] == NULL) != (next[j] == NULL)) {
                    return false;
                } else if(next[i] != NULL && next[j] != NULL
                        && next[i]->val != next[j]->val) {
                    return false;
                }
            }
        }
        return true;
    }
};

