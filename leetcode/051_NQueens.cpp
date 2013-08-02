// 15min
class Solution {
    vector<vector<string> > ans;
    vector<bool> has;
    int gn;
public:
    vector<vector<string> > solveNQueens(int n) {
        ans.clear();
        gn = n;
        has.assign(6*gn-2, false);
        vector<string> tmp(gn, string(gn, '.'));
        dfs(tmp, 0);
        return ans;
    }
    
    void dfs(vector<string> &now, int r) {
        if(r == gn) {
            ans.push_back(now);
            return;
        }
        for(int i = 0; i < gn; i++) {
            if(set(now, r, i)) {
                dfs(now, r+1);
                unset(now, r, i);
            }
        }
    }
    
    bool set(vector<string> &b, int r, int c) {
        int lx = gn*2+gn-1-r+c, rx = gn*4-1+r+c;
        if(has[r] || has[gn+c] 
                || has[lx] || has[rx])
            return false;
        b[r][c] = 'Q';
        has[r] = has[gn+c] = has[lx] = has[rx] = true;
        return true;
    }
    
    void unset(vector<string> &b, int r, int c) {
        int lx = gn*2+gn-1-r+c, rx = gn*4-1+r+c;
        b[r][c] = '.';
        has[r] = has[gn+c] = has[lx] = has[rx] = false;
    }
};

