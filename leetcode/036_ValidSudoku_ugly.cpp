// http://leetcode.com/onlinejudge#question_36
// 7min
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int n = board.size();
        if(n != 9) 
            return false;
        int m = board[0].size();
        if(m != 9)
            return false;
        for(int i = 0; i < 9; i++) {
            bool ok = true;
            int bit = 0;
            for(int j = 0; ok && j < 9; j++) {
                if(board[i][j] != '.') {
                    int x = board[i][j]-'1';
                    if(bit&(1<<x)) 
                        ok = false;
                    bit |= 1<<x;
                }
            }
            if (!ok)
                return false;
        }
        for(int i = 0; i < 9; i++) {
            bool ok = true;
            int bit = 0;
            for(int j = 0; ok && j < 9; j++) {
                if(board[j][i] != '.') {
                    int x = board[j][i]-'1';
                    if(bit&(1<<x))
                        ok = false;
                    bit |= 1<<x;
                }
            }
            if (!ok)
                return false;
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                bool ok = true;
                int bit = 0;
                for(int r = i; ok && r < i+3; r++) {
                    for(int c = j; ok && c < j+3; c++) {
                        if(board[r][c] != '.') {
                            int x = board[r][c]-'1';
                            if(bit&(1<<x))
                                ok = false;
                            bit |= 1<<x;
                        }
                    }
                }
                if (!ok)
                    return false;
            }
        }
        return true;
    }
};

