// 15min, 1WA: duplicate combinations
class Solution {
    vector<vector<int> > ans;
    map<int,int> cands;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        cands.clear();
        for(int i = 0; i < num.size(); i++)
            cands[num[i]]++;
        ans.clear();
        vector<int> tmp;
        dfs(tmp, cands.begin(), target);
        return ans;
    }
    
    void dfs(vector<int> &now, map<int,int>::iterator it, int left) {
        if(left == 0) {
            ans.push_back(now);
            return;
        }
        if(it == cands.end())
            return;
        int up = min(it->second, left/it->first);
        for(int i = 0; i <= up; i++) {
            if(i > 0)
                now.push_back(it->first);
            dfs(now, ++it, left-i*it->first);
            --it;
        }
        now.resize(now.size()-up);
    }
};

