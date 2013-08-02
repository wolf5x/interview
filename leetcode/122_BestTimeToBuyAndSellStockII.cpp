// 5min
// O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        for(int i = prices.size()-1; i >= 0; i--) {
            int j = i;
            while(j > 0 && prices[j-1] <= prices[j])
                j--;
            ans += prices[i]-prices[j];
            i = j;
        }
        return ans;
    }
};

