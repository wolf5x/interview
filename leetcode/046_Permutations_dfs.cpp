// 2min, 1AC
// dfs, duplicate elements not allowed
class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int> > permute(vector<int> &num) {
        ans.clear();
        dfs(num, 0);
        return ans;
    }
    
    void dfs(vector<int> &num, int pos) {
        if(pos == num.size()) {
            ans.push_back(num);
            return;
        }
        for(int i = pos; i < num.size(); i++) {
            swap(num[i], num[pos]);
            dfs(num, pos+1);
            swap(num[i], num[pos]);
        }
    }
};

