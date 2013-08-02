// 5min, 1AC
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "0";
        int la = a.length(), lb = b.length();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int c = 0;
        for(int i = 0; i < la || i < lb || c > 0; i++) {
            while(ans.length() < i+1)
                ans += '0';
            int x = ans[i]-'0' + c + (i<la ? a[i]-'0' : 0) + (i<lb ? b[i]-'0' : 0);
            c = x>>1;
            x &= 1;
            ans[i] = '0'+x;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

