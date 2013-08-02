// http://leetcode.com/onlinejudge#question_108
// 7min
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
    
    TreeNode *sortedArrayToBST(vector<int>::iterator begin, vector<int>::iterator end) {
        int n = end-begin;
        if (n <= 0)
            return NULL;
        int m = n/2;
        TreeNode *ret = new TreeNode(*(begin+m));
        ret->left = sortedArrayToBST(begin, begin+m);
        ret->right = sortedArrayToBST(begin+m+1, end);
        return ret;
    }
};

