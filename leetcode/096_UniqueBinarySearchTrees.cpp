// 15min
// Catalan
class Solution {
    vector<vector<int> > c;
public:
    int numTrees(int n) {
        c.assign(n*2+1, vector<int>(n*2+1, -1));
        return getc(n*2, n)/(n+1);
    }
    
    int getc(int n, int k) {
        return k>n || k<0 ? 0
            : c[n][k] >= 0 ? c[n][k]
            : k == n || k == 0 ? 1
            : (c[n][k] = getc(n-1, k)+getc(n-1, k-1));
    }
};

