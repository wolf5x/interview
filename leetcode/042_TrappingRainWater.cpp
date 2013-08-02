// 15min
// time O(n), space O(n)
class Solution {
public:
    int trap(int A[], int n) {
        vector<int> h(n+2, 0);
        h[0] = h[n+1] = 0;
        for(int i = 1; i <= n; i++)
            h[i] = max(h[i-1], A[i-1]);
        int ans = 0;
        for(int i = n; i >= 1; i--) {
            int lh = h[i-1], rh = h[i+1];
            ans += max(0, min(h[i-1], h[i+1])-A[i-1]);
            
            h[i] = max(h[i+1], A[i-1]);
        }
        return ans;
    }
};

