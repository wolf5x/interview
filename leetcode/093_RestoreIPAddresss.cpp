// 30min..
class Solution {
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        vector<int> tmp;
        dfs(tmp, 0, s);
        return ans;
    }
    
    void dfs(vector<int> now, int p, string &s) {
        if(s.length()-p > (4-now.size())*3 || s.length()-p < 4-now.size())
            return;
        if(p == s.length()) {
            if(now.size() == 4) {
                ans.push_back("");
                for(int i = 0, j = 0; i < 4; j += now[i++]) {
                    if(i) ans.back() += '.';
                    ans.back() += s.substr(j, now[i]);
                }
            }
            return;
        }
        for(int i = p, t = 0; p < s.length(); i++) {
            t = t*10 + s[i]-'0';
            if(t > 255 || i>p && t<10) { // "0x"
                break;
            } else {
                now.push_back(i-p+1);
                dfs(now, i+1, s);
                now.pop_back();
            }
        }
    }
};

