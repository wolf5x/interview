class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char,int> has;
        int l = s.length(), p1 = 0, p2 = 0;
        while(p2 < l) {
            while(p1 < p2 && has[s[p2]] > 0)
                has[s[p1++]]--;
            has[s[p2++]]++;
            ans = max(ans, p2-p1);
        }
        return ans;
    }
};

