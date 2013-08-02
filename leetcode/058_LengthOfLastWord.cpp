// 5min, 1AC
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ans = 0;
        int tmp = 0;
        for(; *s; s++) {
            if(*s == ' ') {
                tmp = 0;
            } else {
                tmp++;
                ans = tmp;
            }
        }
        return ans;
    }
};

