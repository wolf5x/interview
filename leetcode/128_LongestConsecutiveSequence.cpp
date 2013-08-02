// 10min
// O(n): unordered_set
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> google;
        for(int i = 0; i < num.size(); i++)
            google.insert(num[i]);
        int ans = 0;
        for(int i = 0; i < num.size(); i++) {
            if (google.count(num[i])>0) {
                int tmp = 0;
                for(int j = num[i]; google.count(j)>0; j--) {
                    google.erase(j);
                    tmp++;
                }
                for(int j = num[i]+1; google.count(j)>0; j++) {
                    google.erase(j);
                    tmp++;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};

