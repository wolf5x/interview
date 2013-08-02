// 20min, 1AC
// O(n^2)
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ar(n+1, 1);
        for(int i = 1; i <= n; i++)
            ar[i] = ar[i-1]*i;
        vector<char> fig(n);
        for(int i = 0; i < n; i++)
            fig[i] = '1'+i;
        string ans = "";
        for(int i = 0; i < n; i++) {
            int j = (k+ar[n-1-i]-1)/ar[n-1-i];
            k -= ar[n-1-i]*(j-1);
            ans += fig[j-1];
            fig.erase(fig.begin()+j-1);
        }
        return ans;
    }
};

