LeetCode
===

Solutions of problems on [LeetCode](http://leetcode.com/onlinejudge).

## Solution

| No. | Problem | Idea | Difficulty | Tag | Note |
|---:|:---|:---|:---:|:---:|:---|
| 004 | Median of Two Sorted Arrays | A more general question: Kth of two sorted arrays.<br>Each time compare the k/2th element of the two arrays, and narrow down the range to half.<br>Refer to [google][link_004]. | hard | trick, binary search ||
| 010 | Regular Expression Matching | O(mn) DP. | medium | string, dp ||
| 044 | Wildcard Matching | O(m+n): split the pattern string with '\*' into P[]. For P[i], greedily match it to the earlest substring in S. Then for P[i+1], match it to the earlest substring in the rest of S. Go on like this. Do each matching using KMP can make the amortized time O(m+n). | hard | string, kmp, greedy, dp ||
| 065 | Valid Number | Think in automata way. Don't miss details. | medium | simulate ||
| 076 | Minimum Window Substring | Two pointers sweeping(much like a deque representing the window). Count the number of each character in current window. In each step, minimize the window to make it *just* satisfy the need. | medium | deque, sweeping, hash ||
| 086 | Partition List | Two pointers. One points to the tail of the 'less than' part of the list. The other points to the 'currently processing' node. | easy | list ||
| 087 | Scramble String | O(n^4) DP.<br>dp\[i]\[j]\[k]: are S[i..i+k-1] and T[j..j+k-1] scrambled strings?  | medium | dp | Faster than O(n^4)? |
| 099 | Recover Binary Search Tree | Do inorder traversal on a binary tree in O(n) time, O(1) extra space: [Threaded Binary Tree][link_099]. | hard | tree, space ||
| 101 | Symmetric Tree | Iteratively: layer by layer.<br>Recursively: dfs. | easy | tree ||
| 109 | Convert Sorted List to Binary Search Tree | List order is the INORDER of the tree. So build the tree in INORDER. | medium | tree, recursion ||
| 114 | Flatten Binary Tree to Linked List | Recursively: first right child, then left child. Return the head node of the flattened tree. | medium | tree, list ||
| 115 | Distinct Subsequences | O(mn) DP. dp\[m]\[n]. | easy | dp ||
| 117 | Populating Next Right Pointers in Each Node II | Iterate layer by layer. For each layer, proceed from left to right, and store the first non-null child of the next layer. | easy | tree, list ||
| 119 | Pascal's Triangle II | O(1) extra space in addition to the answer array: update the array from end to begin. | easy | math, space ||
| 126 | Word Ladder II | O(26nL) bfs | medium | search ||
| 128 | Longest Consecutive Sequence | O(n). Start from any integer in the set, try to extend as far as possible in both directions. Remove the used integers from the set. | medium | trick ||

[link_004]:https://www.google.com/#q=Median+of+Two+Sorted+Arrays+leetcode
[link_099]:http://en.wikipedia.org/wiki/Threaded_binary_tree

*To be supplemented.*
