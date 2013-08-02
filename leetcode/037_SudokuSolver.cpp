// 30min, 1AC
class Solution {
    vector<vector<bool>> has;
public:
    void solveSudoku(vector<vector<char> > &board) {
        has.assign(27, vector<bool>(9));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    set(board, i, j, board[i][j]);
                }
            }
        }
        solve(board, 0);
    }
    
    bool solve(vector<vector<char> > &b, int p) {
        if(p == 81)
            return true;
        int r = p/9, c = p%9;
        if(b[r][c] != '.')
            return solve(b, p+1);
        for(char x = '1'; x <= '9'; x++) {
            if(isok(b, r, c, x)) {
                set(b, r, c, x);
                if(solve(b, p+1))
                    return true;
                unset(b, r, c);
            }
        }
        return false;
    }
    
    void set(vector<vector<char> > &b, int r, int c, char x) {
        b[r][c] = x;
        int y = x-'1';
        has[r][y] = has[9+c][y] = has[18+r/3*3+c/3][y] = true;
    }
    
    void unset(vector<vector<char> > &b, int r, int c) {
        int y = b[r][c]-'1';
        b[r][c] = '.';
        has[r][y] = has[9+c][y] = has[18+r/3*3+c/3][y] = false;
    }
    
    bool isok(vector<vector<char> > &b, int r, int c, char x) {
        int y = x-'1';
        return !(has[r][y] || has[9+c][y] || has[18+r/3*3+c/3][y]);
    }
    
};

