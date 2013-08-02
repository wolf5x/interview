// 正推求k步最远能到达多远
class Solution {
public:
    int jump(int A[], int n) {
        int lo = 0, hi = 0;
        int ans = 0;
        while(hi < n-1) {
            ans++;
            int nhi = hi;
            for(int i = lo; i <= hi; i++) {
                nhi = max(nhi, i+A[i]);
            }
            lo = hi+1, hi = nhi;
        }
        return ans;
    }
};

