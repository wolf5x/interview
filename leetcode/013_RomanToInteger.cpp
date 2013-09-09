/**
 * http://leetcode.com/onlinejudge#question_13
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman({
           {'I', 1}, {'X', 10}, {'C', 100}, {'M', 1000},
           {'V', 5}, {'L', 50}, {'D', 500}
        });
        int ans = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (i == s.length()-1 || roman[s[i]] >= roman[s[i+1]]) {
                ans += roman[s[i]];
            } else {
                ans -= roman[s[i]];
            }
        }
        return ans;
    }
};

