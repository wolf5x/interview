// 2min
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p = m-1, q = n-1;
        for(int i = m+n-1; i >= 0; i--) {
            if(p < 0)
                A[i] = B[q--];
            else if(q < 0)
                A[i] = A[p--];
            else if(A[p] < B[q])
                A[i] = B[q--];
            else
                A[i] = A[p--];
        }
    }
};

