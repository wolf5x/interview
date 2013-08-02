// http://leetcode.com/onlinejudge#question_35
// 5min
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int lo = 0, hi = n-1;
        int lb = n;
        while(lo <= hi) {
            int mi = (lo+hi)>>1;
            if(A[mi] < target)
                lo = mi+1;
            else
                lb = mi, hi = mi-1;
        }
        return lb;
    }
};

