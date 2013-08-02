// 20min, 1AC
// Manacher, O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        string gs = "";
        for(int i = 0; i < s.length(); i++) {
            gs += i > 0 ? "#" : "";
            gs += s[i];
        } 
        int ansp = -1, ansr = -1;
        // Manacher
        vector<int> radius(gs.length(), 0);
        int mx = -1, id = -1;
        for(int i = 0; i < gs.length(); i++) {
            int mr = 2*id-i >= 0 ? radius[2*id-i] : 0;
            int tr = 0;
            if(mx >= i) {
                tr = min(mx-i, mr);
            }
            while(i+tr+1 < gs.length() && i-tr-1 >= 0
                    && gs[i+tr+1] == gs[i-tr-1]) {
                tr++;
            }
            if (mx < i+tr) {
                mx = i+tr;
                id = i;
            }
            radius[i] = tr;
            if(tr > ansr || tr == ansr && i%2 == 1) {
                ansp = i, ansr = tr;
            }
        }
        string ans = "";
        for(int i = ansp-ansr; i <= ansp+ansr; i++) {
            if(i%2 == 0)
                ans += gs[i];
        }
        return ans;
    }
};

