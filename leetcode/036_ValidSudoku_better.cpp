// 10min
class Solution {
    vector<int> has;
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        has.assign(27, 0);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.' 
                        && !set(board, i, j, board[i][j]))
                    return false;
            }
        }
        return true;
    }
    
    bool set(vector<vector<char> > &b, int r, int c, char x) {
        int y = x-'1';
        if(1<<y&has[r] || 1<<y&has[9+c] || 1<<y&has[18+r/3*3+c/3])
            return false;
        has[r] |= 1<<y;
        has[9+c] |= 1<<y;
        has[18+r/3*3+c/3] |= 1<<y;
        return true;
    }
};

