// 25min, 2WA
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = solve(s, '(', ')');
        reverse(s.begin(), s.end());
        ans = max(ans, solve(s, ')', '('));
        return ans;
    }
    
    int solve(string &s, char o, char c) {
        int ans = 0;
        int opened = 0, head = 0;
        for(int i = 0; i < s.length(); i++ ){
            opened += s[i] == o ? 1 : -1;
            if(opened == 0) {
                ans = max(ans, i-head+1);
            } else if(opened < 0) {
                opened = 0;
                head = i+1;
            }
        }
        return ans;
    }
};

