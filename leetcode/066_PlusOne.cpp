// 3min, 1AC
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;
        for(int i = digits.size()-1; c > 0; i--) {
            while(i < 0) {
                digits.insert(digits.begin(), 0);
                i++;
            }
            int x = c + digits[i];
            c = x/10;
            x %= 10;
            digits[i] = x;
        }
        return digits;
    }
};

