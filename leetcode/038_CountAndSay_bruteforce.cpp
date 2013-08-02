// 9min, 1AC
// brute-force simulate
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) 
            return "1";
        string s = countAndSay(n-1);
        return convert(s);
    }
    
    string convert(string &s) {
        string r = "";
        for(int i = 0; i < s.length(); ) {
            int j = i+1;
            while(j < s.length() && s[j] == s[i]) {
                j++;
            }
            r += itoa(j-i);
            r += s[i];
            i = j;
        }
        return r;
    }
    
    string itoa(int x) {
        string r = "";
        do {
            r += '0'+x%10;
            x /= 10;
        } while(x);
        reverse(r.begin(), r.end());
        return r;
    }
};

