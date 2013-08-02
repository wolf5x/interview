class Solution {
    string letters[10] = {
        " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        solve(digits, 0, "");
        return ans;
    }
    
    void solve(string digits, int pos, string now) {
        if(pos == digits.length()) {
            ans.push_back(now);
            return;
        }
        int idx = digits[pos]-'0';
        for(int i = 0; i < letters[idx].length(); i++) {
            solve(digits, pos+1, now+letters[idx][i]);
        }
    }
};

