class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int t = 1;
        while(x/t > 9) t *= 10;
        bool ok = true;
        for(int p = 1; p <= t; p*=10, t/=10) {
            if(getdigit(x,p) != getdigit(x,t))
                return false;
        }
        return true;
    }
    
    int getdigit(int x, int ten) {
        return x/ten%10;
    }
};

