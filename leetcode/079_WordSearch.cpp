// 20min, 1TLE
class Solution {
    vector<vector<int> > vis;
    int stamp;
    int n, m;
    const int dr[4] = {0,1,0,-1};
    const int dc[4] = {1,0,-1,0};
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty())
            return true;
        m = board.size(), n = board[0].size();
        vis.assign(m, vector<int>(n, -1));
        stamp = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ++stamp;
                if(dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char> > &b, int r, int c, int p, string &w) {
        if(b[r][c] != w[p])
            return false;
        if(p == w.length()-1)
            return true;
        vis[r][c] = stamp;
        for(int k = 0; k < 4; k++){
            int nr = r+dr[k], nc = c+dc[k];
            if(nr>=0 && nr< m && nc>=0 && nc<n && vis[nr][nc] != stamp
                    && dfs(b, nr, nc, p+1, w))
                return true;
        }
        vis[r][c] = -1;
        return false;
    }
};

