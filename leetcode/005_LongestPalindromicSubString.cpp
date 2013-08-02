// http://leetcode.com/onlinejudge#question_5
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            string tmp = solve(s, i, i);
            if(tmp.length() > ans.length())
                ans = tmp;
            tmp = solve(s, i, i+1);
            if(tmp.length() > ans.length())
                ans = tmp;
        }
        return ans;
    }
    
    string solve(string &s, int x, int y) {
        while(x >= 0 && y < s.length() && s[x] == s[y]) {
            --x, ++y;
        }
        ++x, --y;
        return x <= y ? s.substr(x, y-x+1) : string("");
    }
};
