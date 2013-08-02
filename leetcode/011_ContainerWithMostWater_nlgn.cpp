class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        vector<pair<int,int>> h(n);
        for(int i = 0; i < n; i++) {
            h[i] = make_pair(height[i], i);
        }
        sort(h.begin(), h.end());
        int lo = 1<<30, hi = -(1<<30);
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            lo = min(lo, h[i].second);
            hi = max(hi, h[i].second);
            ans = max(ans, h[i].first*(hi-lo));
        }
        return ans;
    }
};

