// INT_MAX, overflow!!!
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<int> a(num);
        int x = findGe(a, target);
        for(int i = 0; i < a.size(); i++)
            a[i] = -a[i];
        int y = -findGe(a, -target);
        return x-target < target-y ? x : y;
    }
    
    int findGe(vector<int> &a, int s) {
        sort(a.begin(), a.end());
        int r = INT_MAX>>1;
        for(int i = 0; i < a.size(); i++) {
            int p = i+1, q = a.size()-1;
            while(p < q) {
                while(p < q && a[i]+a[p]+a[q]<s) p++;
                while(p < q && a[i]+a[p]+a[q]>=s) {
                    r = min(r, a[i]+a[p]+a[q]);
                    q--;
                }
            }
        }
        return r;
    }
};

