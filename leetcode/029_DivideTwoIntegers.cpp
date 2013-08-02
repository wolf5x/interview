// 5min
// 补码转原码
class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        int sgn = dividend >= 0 && divisor >= 0
                || dividend < 0 && divisor < 0 
                ? 1 : -1;
        unsigned int dd = dividend;
        if (dividend < 0) {
            dd = ~(dd-1);
        }
        unsigned int ds = divisor;
        if (divisor < 0) {
            ds = ~(ds-1);
        }
        unsigned int base = 1;
        while(dd>>1 >= ds) {
            ds <<= 1;
            base <<= 1;
        }
        while(base > 0) {
            if (dd >= ds) {
                ans |= base;
                dd -= ds;
            }
            base >>= 1;
            ds >>= 1;
        }
        return sgn > 0 ? ans : -ans;
    }
};

