// Boundary: "", "a*b*c*.*"
class Solution {
    vector<vector<int>> dp;
    int m, n;
public:
    bool isMatch(const char *s, const char *p) {
        m = strlen(s);
        n = strlen(p);
        dp.assign(m+1, vector<int>(n+1, -1));
        return dodp(s, 0, p, 0);
    }
    
    bool dodp(const char *s, int x, const char *p, int y) {
        if(x == m && y == n)
            return true;
        if(x < m && y == n)
            return false;
        if(dp[x][y] >= 0)
            return dp[x][y] > 0;
        bool r = false;
        if(p[y] == '*') {
            if(y > 0) {
                r = r || dodp(s, x, p, y-1);
            }
        } else {
            if(y < n-1 && p[y+1] == '*') {
                int z = y+2;
                while(z < n && p[z] == '*') z++;
                r = r || dodp(s, x, p, z);
            }
            if(x < m) {
                r = r || ((p[y] == '.' || s[x] == p[y]) && dodp(s, x+1, p, y+1));
            }
        }
        return dp[x][y] = r ? 1 : 0;
    }
};

