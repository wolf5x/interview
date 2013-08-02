// http://leetcode.com/onlinejudge#question_70
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for(int i = 0; i < n-1; i++) {
            int t = a+b;
            a = b;
            b = t;
        }
        return b;
    }
};

