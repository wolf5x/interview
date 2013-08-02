class Solution {
    string left = "([{";
    string right = ")]}";
public:
    bool isValid(string s) {
        stack<char> stk;
        bool ok = true;
        for(int i = 0; i < s.length(); i++) {
            size_t p;
            p = left.find_first_of(s[i]);
            if (p != string::npos) {
                stk.push(right[p]);
                continue;
            }
            p = right.find_first_of(s[i]);
            if (p != string::npos) {
                if(stk.empty() || stk.top() != s[i]) {
                    ok = false;
                    break;
                } else {
                    stk.pop();
                }
                continue;
            }
        }
        ok = ok && stk.empty();
        return ok;
    }
};

