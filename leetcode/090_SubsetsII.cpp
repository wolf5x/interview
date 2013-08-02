// 20min
class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        ans.clear();
        vector<int> tmp;
        dfs(tmp, 0, S);
        return ans;
    }
    
    void dfs(vector<int> &now, int p, vector<int> &s) {
        if(p == s.size()){
            ans.push_back(now);
            return ;
        }
        int q = p+1;
        while(q < s.size() && s[p] == s[q])
            q++;
        for(int i = q; i >= p; i--) {
            if(i < q)
                now.push_back(s[p]);
            dfs(now, q, s);
        }
        for(int i = q-1; i >= p; i--)
            now.pop_back();
    }
};

