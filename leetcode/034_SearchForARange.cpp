// http://leetcode.com/onlinejudge#question_34
// 15min
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lb = n, ub = -1;
        int lo, hi;
        lo = 0, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)>>1;
            if(A[mi] < target)
                lo = mi + 1;
            else 
                lb = mi, hi = mi - 1; 
        }
        lo = 0, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)>>1;
            if(A[mi] <= target) 
                ub = mi+1, lo = mi+1;
            else
                hi = mi-1;
        }
        if(lb < ub && A[lb] == target && A[ub-1] == target)
            return vector<int>({lb, ub-1});
        else
            return vector<int>({-1,-1});
    }
};

