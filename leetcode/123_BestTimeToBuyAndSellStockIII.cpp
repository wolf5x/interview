// 10min
// O(n): DP
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> one(n+1, 0);
        int h = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            h = max(h, prices[i]);
            one[i] = max(one[i+1], h-prices[i]);
        }
        int ans = one[0];
        h = INT_MAX;
        for(int i = 0; i < n; i++) {
            h = min(h, prices[i]);
            one[i] = prices[i]-h;
            if (i) 
                one[i] = max(one[i], one[i-1]);
            ans = max(ans, one[i]+one[i+1]);
        }
        return ans;
    }
};

