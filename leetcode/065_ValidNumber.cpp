// 20min, 1AC
// grammar of a 'valid number'
class Solution {
public:
    bool isNumber(const char *s) {
        int p = 0;
        skipWhiteSpace(s, p);
        if(!checkSignedDecimal(s, p))
            return false;
        if((s[p] == 'e' || s[p] == 'E') && !checkSignedInteger(s, ++p))
            return false;
        skipWhiteSpace(s, p);
        if(s[p])
            return false;
        return true;
    }
    
    bool checkSignedDecimal(const char *s, int &p) {
        if(s[p] == '+' || s[p] == '-')
            return checkUnsignedDecimal(s, ++p);
        else
            return checkUnsignedDecimal(s, p);
    }
    
    bool checkUnsignedDecimal(const char *s, int &p) {
        bool intBeforeRadix = checkUnsignedInteger(s, p);
        bool intAfterRadix = false;
        if(s[p] == '.')
            intAfterRadix = checkUnsignedInteger(s, ++p);
        return intBeforeRadix || intAfterRadix;
    }
    
    bool checkSignedInteger(const char *s, int &p) {
        if(s[p] == '+' || s[p] == '-')
            return checkUnsignedInteger(s, ++p);
        else 
            return checkUnsignedInteger(s, p);
    }
    
    bool checkUnsignedInteger(const char *s, int &p) {
        bool ok = false;
        while(s[p] && isdigit(s[p])) 
            ok = true, p++;
        return ok;
    }
    
    void skipWhiteSpace(const char *s, int &p) {
        while(s[p] == ' ') p++;
    }
};

