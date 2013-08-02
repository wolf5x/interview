class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0, highest;
        for(int i = prices.size()-1; i >= 0; i--) {
            highest = max(highest, prices[i]);
            if (prices[i] < highest)
                ans = max(ans, highest-prices[i]);
        }
        return ans;
    }
};

