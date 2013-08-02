// 10min, 2WA
// abs(x)会溢出!!!!!!
class Solution {
public:
    double pow(double x, int n) {
        double ans = 1.0;
        double y = x;
        bool neg = n < 0;
        unsigned int m = n;
        if(neg) m = ~(m-1);
        while(m) {
            if(m&1) ans *= y;
            y *= y;
            m >>= 1;
        }
        return neg ? 1.0/ans : ans;
    }
};

