class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> a(num);
        int n = num.size();
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int p = j+1, q = n-1;
                while(p < q) {
                    while (p < q && a[i]+a[j]+a[p]+a[q]<target) {
                        p++;
                    }
                    while (p < q && a[i]+a[j]+a[p]+a[q]>target) {
                        q--;
                    }
                    if (p < q && a[i]+a[j]+a[p]+a[q] == target) {
                        vector<int> got({a[i], a[j], a[p], a[q]});
                        ans.push_back(got);
                        while(p < q && a[p] == a[p+1]) {
                            p++;
                        }
                        p++;
                        while(p < q && a[q] == a[q-1]) {
                            q--;
                        }
                    }
                }
                while(j < n-1 && a[j]==a[j+1]) {
                    j++;
                }
            }
            while(i < n-1 && a[i]==a[i+1]) {
                i++;
            }
        }
        return ans;
    }
};

