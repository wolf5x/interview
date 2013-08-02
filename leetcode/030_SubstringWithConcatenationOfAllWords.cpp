// 40min, 1WA
// 居然没有考虑L里的词有重复...
// hash, nlgn
class Solution {
    vector<unsigned int> hash, ex;
    const unsigned int C = 31;
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int n = L.size();
        vector<int> ans;
        if(n == 0) {
            return ans;
        }
        int len = L[0].length();
        buildhash(S);
        // store hash and id of each word in the list
        map<unsigned int, int> wid;
        map<int, int> wcount;
        for(int i = 0; i < n; i++) {
            unsigned int h = 0;
            for(int j = 0; j < len; j++)
                h = h*C + L[i][j];
            if(wid.count(h) == 0) {
                wid[h] = i;
            } 
            wcount[wid[h]]++;
        }
        // iterator S
        for(int i = 0; i < len; i++) {
            map<int, int> has;
            int hit = 0;
            for(int j = i, k = i; j+len-1 < S.length(); j += len) {
                unsigned int h = gethash(S, j, len);
                map<unsigned int, int>::iterator it = wid.find(h);
                if(it != wid.end()) {
                    int id = it->second;
                    while(k < j && has[id] >= wcount[id]) {
                        has[wid[gethash(S, k, len)]]--;
                        hit--;
                        k += len;
                    }
                    has[id]++;
                    hit++;
                    if(hit == n) {
                        ans.push_back(k);
                    }
                } else {
                    has.clear();
                    hit = 0;
                    k = j+len;
                }
            } 
        }
        return ans;
    }

    void buildhash(string &s) {
        hash.resize(s.length()+1);
        ex.resize(s.length()+1);
        hash[0] = 0, ex[0] = 1;
        for(int i = 0; i < s.length(); i++) {
            hash[i+1] = hash[i]*C + s[i];
            ex[i+1] = ex[i]*C;
        } 
    }
    
    unsigned int gethash(string &s, size_t pos, size_t len) {
        return hash[pos+len] - hash[pos]*ex[len];
    }
};

