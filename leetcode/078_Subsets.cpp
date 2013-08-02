// 4min
class Solution {
    vector<vector<int> > ans;
    vector<int> tmp;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        ans.clear();
        tmp.clear();
        sort(S.begin(), S.end());
        dfs(0, S);
        return ans;
    }
    
    void dfs(int p, vector<int> &s) {
        if(p == s.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(s[p]);
        dfs(p+1, s);
        tmp.pop_back();
        dfs(p+1, s);
    }
};

