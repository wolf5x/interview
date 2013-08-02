class Solution {
public:
    bool canJump(int A[], int n) {
        int lo = 0, hi = 0;
        while(lo <= hi) {
            hi = max(hi, lo+A[lo]);
            if(hi >= n-1)
                return true;
            lo++;
        }
        return false;
    }
};

