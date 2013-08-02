class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> a(num);
        int n = num.size();
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            if(i > 0 && a[i] == a[i-1]) {
                continue;
            }
            for(int j = i+1; j < n; j++) {
                if(j > i+1 && a[j] == a[j-1]) {
                    continue;
                }
                int p = j+1, q = n-1;
                while(p < q) {
                    int cmp = a[i]+a[j]+a[p]+a[q]-target;
                    if(cmp < 0) {
                        p++;
                    } else if(cmp > 0) {
                        q--;
                    } else {
                        vector<int> got({a[i], a[j], a[p], a[q]});
                        ans.push_back(got);
                        do { p++; }
                        while (p < q && a[p] == a[p-1]);
                    }
                }
            }
        }
        return ans;
    }
};

