/**
 * http://leetcode.com/onlinejudge#question_12
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string one = "IXCM";
        string fiv = "VLD";
        string ans = "";
        for (int i = 0; num > 0; i++, num/=10) {
            int dig = num%10;
            if (dig <= 3) {
                ans = string(dig, one[i]) + ans;
            } else if (dig <= 5) {
                ans = string(5-dig, one[i]) + fiv[i] + ans;
            } else if (dig <= 8) {
                ans = fiv[i] + string(dig-5, one[i]) + ans;
            } else {
                ans = string(10-dig, one[i]) + one[i+1] + ans;
            }
        }
        return ans;
    }
};

