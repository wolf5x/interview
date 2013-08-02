// 10min
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        map<string, vector<string> > mem;
        for(int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            mem[t].push_back(strs[i]);
        }
        for(map<string, vector<string> >::iterator it = mem.begin();
                it != mem.end(); ++it) {
            if(it->second.size() > 1) {
                ans.insert(ans.end(), it->second.begin(), it->second.end());
            }    
        }
        return ans;
    }
};

