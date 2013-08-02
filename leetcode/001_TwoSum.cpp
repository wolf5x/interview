class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        vector<pair<int,int>> g;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            g.push_back(make_pair(numbers[i], i+1));
        }
        sort(g.begin(), g.end());
        int p1 = 0, p2 = n-1;
        while(p1 < p2) {
            while(p1 < p2 && g[p1].first+g[p2].first < target) p1++;
            while(p1 < p2 && g[p1].first+g[p2].first > target) p2--;
            if(p1 < p2 && g[p1].first+g[p2].first == target) {
                ans.push_back(g[p1].second);
                ans.push_back(g[p2].second);
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
};

