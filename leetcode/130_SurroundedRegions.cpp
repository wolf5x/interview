// 15min
// bfs
class Solution {
    const int dr[4] = {0,0,1,-1};
    const int dc[4] = {-1,1,0,0};
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0)
            return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i< m; i++) {
            for(int j = 0; j < n; j += (i==0||i==m-1?1:n-1)) {
                if (board[i][j] == 'O') {
                    queue<pair<int,int> > q;
                    q.push(make_pair(i,j));
                    board[i][j] = '.';
                    while(!q.empty()) {
                        pair<int,int> coord = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int u = coord.first+dr[k], v = coord.second+dc[k];
                            if(u>=0 && u<m && v>=0 && v<n
                                    && board[u][v] == 'O') {
                                board[u][v] = '.';
                                q.push(make_pair(u,v));
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = (board[i][j]=='.'?'O':'X');
    }
};

