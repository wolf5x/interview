// 15min, 1WA
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while(!isdigit(num1.back()))
            num1.pop_back();
        while(!isdigit(num2.back()))
            num2.pop_back();
        string ans = "0";
        for(int i = 0; i < num2.length(); i++) {
            for(int j = 0; j < num1.length(); j++) {
                // multipliy bit
                int x = (num1[j]-'0')*(num2[i]-'0');
                // do carry
                for(int k = i+j; x > 0; k++) {
                    while (ans.length() < k+1) // WA here if(..)
                        ans += '0';
                    x += ans[k]-'0';
                    int c = x/10;
                    x %= 10;
                    ans[k] = x+'0';
                    x = c;
                }
                
            }
        }
        for(int i = ans.length()-1; i > 0 && ans[i] == '0'; i--) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

