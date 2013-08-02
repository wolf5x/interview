// len*n*lgn
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = L.size();
        if(n == 0) {
            return ans;
        }
        int len = L[0].length();
        map<string, int> word;
        for(int i = 0; i < n; i++) {
            word[L[i]]++;
        }
        for(int i = 0; i < len; i++) {
            map<string, int> count;
            int hit = 0;
            for(int j = i, k = i; j+len-1 < S.length(); j += len) {
                string tw = S.substr(j, len);
                if(word.count(tw) > 0) {
                    while(k < j && count[tw] >= word[tw]) {
                        count[S.substr(k, len)]--;
                        hit--;
                        k += len;
                    }
                    count[tw]++;
                    hit++;
                    if(hit == n) {
                        ans.push_back(k);
                    }
                } else {
                    count.clear();
                    k = j+len;
                    hit = 0;
                }
            }
        }
        return ans;
    }
};

