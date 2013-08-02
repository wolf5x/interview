// 7min
class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        solve("", n, 0);
        return ans;
    }
    
    void solve(string now, int toopen, int opened) {
        if(toopen == 0 && opened == 0) {
            ans.push_back(now);
            return;
        }
        if (toopen > 0) {
            solve(now + '(', toopen-1, opened+1);
        }
        if (opened > 0) {
            solve(now + ')', toopen, opened-1);
        }
    }
};

