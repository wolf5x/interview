// 7min
// O(n)
class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> ok(n+1, 0);
        ok[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            int to = ok[i+1] - ok[min(i+A[i]+1, n)];
            ok[i] = (to > 0) + ok[i+1];
        }
        return ok[0] > ok[1];
    }
};

