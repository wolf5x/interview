// 15min, tree array
class Solution {
    int maxsz;
    vector<int> tree;
public:
    int jump(int A[], int n) {
        if(n == 0)
            return 0;
        for(maxsz = 1; maxsz < n; maxsz <<= 1);
        tree.assign(maxsz+1, INT_MAX);
        update(n, 0);
        for(int i = n-1; i >= 1; i--) {
            int dp = query(i+A[i-1]);
            if(dp < INT_MAX) {
                dp = dp+1;
                update(i, dp);
            }
        } 
        return query(1);
    }
    
    void update(int p, int v) {
        for(; p <= maxsz; p += p&(-p))
            tree[p] = min(tree[p], v);
    }
    
    int query(int p) {
        int r = INT_MAX;
        for(; p > 0; p -= p&(-p))
            r = min(r, tree[p]);
        return r;
    }
};

