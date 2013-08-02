// 5min, 1WA
// !! 0, INT_MAX!
class Solution {
public:
    int sqrt(int x) {
        if (x == 0) // wa 
            return 0;
        int ans = 1, lo = 1, hi = x;
        while(lo <= hi) {
            int mi = (lo+hi)/2;
            if(x/mi < mi) 
                hi = mi-1;
            else
                ans = mi, lo = mi+1;
        }
        return ans;
    }
};

