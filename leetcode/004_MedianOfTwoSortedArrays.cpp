// The algorithm is a little bit tricky.
// Pay attention to the boundaries.
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int s = m+n;
        if(s%2) {
            return solve(A, m, B, n, s/2+1);
        } else {
            return 0.5*(solve(A, m, B, n, s/2)+solve(A, m, B, n, s/2+1));
        }
    }
    
    int solve(int A[], int m, int B[], int n, int k) {
        if(m>n)
            return solve(B, n, A, m, k);
        if(m == 0)
            return B[k-1];
        if(k == 1)
            return min(A[0], B[0]);
        int pa = min(m, k/2), pb = k-pa;
        if(A[pa-1] < B[pb-1]) 
            return solve(A+pa, m-pa, B, pb, k-pa);
        else if(A[pa-1] > B[pb-1])
            return solve(A, pa, B+pb, n-pb, k-pb);
        else 
            return A[pa-1];
    }
};

