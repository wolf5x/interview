// http://leetcode.com/onlinejudge#question_33
// Improved: 1 bsearch pass.
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo = 0, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)/2;
            if (A[mi] == target)
                return mi;
            if (A[lo] <= A[mi]) {
                if (A[lo] <= target && target < A[mi]) {
                    hi = mi-1;
                } else {
                    lo = mi+1;
                }
            } else {
                if (A[mi] < target && target <= A[hi]) {
                    lo = mi+1;
                } else {
                    hi = mi-1;
                }
            }
            
        }
        return -1;
    }
};
