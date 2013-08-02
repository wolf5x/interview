class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        vector<int> now;
        dfs(now, 1, n, k);
        return ans;
    }
    
    void dfs(vector<int> &now, int p, int n, int k) {
        if(now.size() == k){
            ans.push_back(now);
            return;
        }
        for(int i = p; i <= n && n-i >= k-now.size()-1; i++) {
            now.push_back(i);
            dfs(now, i+1, n, k);
            now.pop_back();
        }
    }
};

