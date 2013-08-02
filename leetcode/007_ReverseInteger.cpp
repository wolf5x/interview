// learn to challenge the unclear points of the problem 
class Solution {
public:
    int reverse(int x) {
        int s = x>=0 ? 1 : -1;
        int y = 0;
        do {
            y = y*10 + x%10;
            x /= 10;
        } while(x);
        return y;
    }
};

