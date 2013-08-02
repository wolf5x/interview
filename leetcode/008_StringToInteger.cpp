// Consider all the possible inputs before coding!
const int MAX_INT = 0x7fffffff;
const int MIN_INT = 0x80000000;
class Solution {
public:
    int atoi(const char *str) {
        long long ans = 0, sig = 0;
        skip_ws(str);
        while(true) {
            char ch = *(str++);
            if(ch == '+' && !sig) sig = 1;
            else if(ch == '-' && !sig) sig = -1;
            else if(isdigit(ch)){
                ans = ans*10 + (ch-'0');
                if(ans & ~0xffffffff)
                    break;
            }
            else break;
        }
        if(sig == 0) sig = 1;
        ans *= sig;
        if(sig < 0 && ans < MIN_INT) ans = MIN_INT;
        else if(sig > 0 && ans > MAX_INT) ans = MAX_INT;
        return ans;
    }
    
    void skip_ws(const char *&s) {
        while(*s > 0 && *s <= ' ') s++;
    }
};

