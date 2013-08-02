// Be careful of empty vector
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return string("");
        int l = strs[0].size();
        for(int i = 1; i < strs.size(); i++) {
            int p = 0;
            while(p < l && p < strs[i].size()
                && strs[0][p] == strs[i][p])
                p++;
            l = p;
        }
        return strs[0].substr(0, l);
    }
};

