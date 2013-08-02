// 25min, 1TLE
// use bit to store status
class Solution {
    long long mask;
    int ans;
public:
    int totalNQueens(int n) {
        mask = (1LL<<n)-1;
        ans = 0;
        dfs(0, 0, 0);
        return ans;
    }
    
    void dfs(long long c, long long lx, long long rx) {
        if(c == mask) {
            ans++;
            return;
        }
        long long can = mask& ~(c | lx | rx);
        for(; can > 0; can -= can&(-can)) {
            long long b = can&(-can);
            dfs(c|b, (lx|b)>>1, (rx|b)<<1);
        }
    }
};

