// countless mins & countless WA
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int sl = strlen(s), pl = strlen(p);
        bool wild = false;
        int x = 0, y = 0;
        while(x < sl && y < pl) {
            if(p[y] == '*') {
                wild = true;
                y++;
                continue;
            }
            int subp = y;
            while(subp < pl && p[subp] != '*')
                subp++;
            int detp = subp-y;
            if(subp == pl) {
                if(sl-detp < x)
                    return false;
                if(!wild && sl-detp != x)
                    return false;
                return kmp(s+sl-detp, detp, p+y, detp) >= 0;
            }
            int next = kmp(s+x, sl-x, p+y, detp);
            if(next == -1 || (!wild && next != 0))
                return false;
            x += next+detp;
            y += detp;
            wild = false;
        }
        if(x == sl && y < pl) {
            while(y < pl) {
                if(p[y] != '*')
                    return false;
                y++;
            }
            return true;
        }
        return (x == sl && y == pl) || wild;
    }
    
    int kmp(const char *s, int n, const char *p, int m) {
        vector<int> next(m+1, -1);
        int i = 0, j = -1;
        while(i < m) {
            while(j >= 0 && p[i] != p[j] && p[i] != '?' && p[j] != '?')
                j = next[j];
            next[++i] = ++j;
        }
        i = 0, j = 0;
        while(i < n && j < m) {
            while(j >= 0 && s[i] != p[j] && p[j] != '?')
                j = next[j];
            i++, j++;
        }
        if(j == m)
            return i-m;
        else
            return -1;
    }
};

