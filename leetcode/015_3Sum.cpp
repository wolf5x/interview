// Damn boundary
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ans;
        vector<int> a(num);
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size(); i++) {
            int p = i+1, q = a.size()-1;
            while(p < q) {
                while(p < q && a[p]+a[q]+a[i] < 0) p++;
                while(p < q && a[p]+a[q]+a[i] > 0) q--;
                if(p < q && a[p]+a[q]+a[i] == 0) {
                    vector<int> t({a[i], a[p], a[q]});
                    ans.push_back(t);
                    while(p < q && a[p] == a[p+1]) p++;
                    p++;
                    while(p < q && a[q] == a[q-1]) q--;
                }
            }
            while(i < a.size()-1 && a[i] == a[i+1]) i++;
        }
        return ans;
    }
};

