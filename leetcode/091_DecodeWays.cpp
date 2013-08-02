// 7min
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0; // shouldn't this be 1?
        int x1 = 1, x2 = 1;
        for(int i = 0; i < s.length(); i++) {
            int t = 0;
            if(s[i] > '0') 
                t += x1;
            if(i>0 && ((s[i-1] == '1') || (s[i-1] == '2' && s[i] <= '6')))
                t += x2;
            x2 = x1, x1 = t;              
        }
        return x1;
    }
};

