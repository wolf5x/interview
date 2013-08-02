// 75min, n WA
// nlgn
class Solution {
    string gs;
    vector<unsigned long> hl, hr;
    vector<unsigned long> ex;
    unsigned long C = 31;
public:
    string longestPalindrome(string s) {
        gs = "";
        for(int i = 0; i < s.length(); i++) {
            gs += (i>0 ? "#" : "");
            gs += s[i];
        }
        build_hash();
        int ansp = -1, ansl = -1;
        for(int i = 0; i < gs.length(); i++) {
            int tl = bcheck(i);
            if(tl > ansl || tl == ansl && i%2!=0) {
                ansp = i, ansl = tl;
            }
        }
        string ans = "";
        for(int i = ansp-ansl; i <= ansp+ansl; i++) {
            if(i%2 == 0)
                ans += gs[i];
        }
        return ans;
    }
    
    int bcheck(size_t p) {
        int lo = 0, hi = min(p, gs.length()-1-p), ans = lo;
        while(lo <= hi) {
            int mi = (lo+hi)/2;
            if(ismirror(p, mi))
                ans = mi, lo = mi+1;
            else
                hi = mi-1;
        }
        return ans;
    }
    
    void build_hash() {
        size_t l = gs.length();
        hl.resize(l+1);
        hr.resize(l+1);
        ex.resize(l+1);
        hl[0] = 0, hr[l] = 0, ex[0] = 1;
        for(int i = 0; i < l; i++) {
            hl[i+1] = hl[i]*C + gs[i];
            hr[l-1-i] = hr[l-i]*C + gs[l-1-i];
            ex[i+1] = ex[i]*C;
        }
    }
    
    bool ismirror(int mid, int len) {
        unsigned long v1 = hl[mid+1] - hl[mid-len]*ex[len+1];
        unsigned long v2 = hr[mid] - hr[mid+len+1]*ex[len+1];
        return v1 == v2;
    }
    
};
