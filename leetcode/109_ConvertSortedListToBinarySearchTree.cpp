// http://leetcode.com/onlinejudge#question_109
// O(n), recursively: bottom-top, build nodes in INORDER
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        for(ListNode *now = head; now != NULL; now = now->next, n++) ;
        return sortedListToBST(head, 0, n);
    }
    
    TreeNode *sortedListToBST(ListNode *&now, int begin, int end) {
        if (begin >= end)
            return NULL;
        int mid = begin + (end-begin)/2;
        TreeNode *lchild = sortedListToBST(now, begin, mid);
        TreeNode *root = new TreeNode(now->val);
        now = now->next;
        TreeNode *rchild = sortedListToBST(now, mid+1, end);
        root->left = lchild;
        root->right = rchild;
        return root;
    }
};

