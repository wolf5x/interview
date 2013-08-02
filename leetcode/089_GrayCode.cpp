// 20min
// dfs???
// special graph hamiltion path?
class Solution {
    vector<bool> vis;
    vector<int> ans;
public:
    vector<int> grayCode(int n) {
        ans.clear();
        vis.assign(1<<n, false);
        dfs(0, 1<<n, n);
        return ans;
    }
    
    bool dfs(int now, int len, int n){
        vis[now] = true;
        ans.push_back(now);
        if(len <= 1)
            return true;
        for(int i = 0; i < n; i++) {
            int to = now^(1<<i);
            if(!vis[to] && dfs(to, len-1, n))
                return true;
        }
        ans.pop_back();
        vis[now] = false;
    }
};

