// 30min, 2WA
// last line special...
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0; i < n; ) {
            int tl = 0;
            int j = i;
            while(j < n && tl+words[j].length()+j-i <= L) {
                tl += words[j].length();
                j++;
            }
            int x, r;
            if(j < n && j-i >1){
                x = (L-tl)/(j-i-1);
                r = (L-tl)%(j-i-1);
            } else {
                x = 1, r = 0;
            }
            string line = words[i];
            i++;
            for(; i < j; i++) {
                line += string(x+(r>0), ' ');
                r--;
                line += words[i];
            }
            line += string(L-line.length(), ' ');
            ans.push_back(line);
        }
        return ans;
    }
};

