// 9min, 1WA
// "", ""
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        for(char *p = haystack; ; p++) {
            int cmp = isprefix(p, needle);
            if (cmp > 0) {
                return p;
            } else if (cmp < 0) {
                return NULL;
            }
        }
        return NULL;
    }
    
    int isprefix(char *str, char *prefix) {
        while(*str && *prefix) {
            if(*str != *prefix) {
                return 0;
            }
            str++;
            prefix++;
        }
        if (*prefix) {
            return -1;
        } else {
            return 1;
        }
    }
};

