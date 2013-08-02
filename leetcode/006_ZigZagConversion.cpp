// be careful to the bound
class Solution {
public:
    string convert(string s, int nRows) {
        string ans = "";
        int l = s.length(), r = nRows, c = 0;
        int pack = r + max(0,r-2);
        c = l/pack*2;
        int left = l%pack;
        if(left>0) c++;
        if(left>r) c++;
        for(int i = 0, k = 0; i < r && k < l; i++) {
            for(int j = 0; j < c && k < l; j++) {
                int p = getpos(i, j, r);
                if(p >= 0 && p < l) {
                    ans.push_back(s[p]);
                    k++;
                }
            }
        }
        return ans;
    }
    
    int getpos(int i, int j, int n) {
        int p = 0;
        if(j%2 == 1 && (i==0 || i==n-1))
            return -1;
        p += ((j+1)/2)*n;
        p += (j/2)*max(0,n-2);
        if(j%2 == 0)
            p += i;
        else
            p += n-2-i;
        return p;
    }
};

