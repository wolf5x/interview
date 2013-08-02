// 20min, 1WA
// naive dfs
class Solution {
    vector<vector<int>> ans;
    vector<int> cands;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.resize(unique(candidates.begin(), candidates.end())-candidates.begin());
        vector<int> tmp;
        ans.clear();
        solve(candidates, tmp, 0, target);
        return ans;
    }
    
    void solve(vector<int> &cands, vector<int> &now, int pos, int left) {
        if(left == 0) {
            ans.push_back(now);
            return;
        }
        if(pos == cands.size())
            return;
        for(int i = 0; i <= left; i += cands[pos]) {
            if(i > 0)
                now.push_back(cands[pos]);
            solve(cands, now, pos+1, left-i);
        }
        now.resize(now.size()-left/cands[pos]);
    }
};

