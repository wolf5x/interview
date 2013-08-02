class Solution {
public:
    int search(int A[], int n, int target) {
        if(n == 0)
            return -1;
        int pivot = A[0] <= A[n-1] ? n-1 : bsearch_pivot(A, n);
        if(target >= A[0])
            return bsearch_target(A, 0, pivot+1, target);
        else
            return bsearch_target(A, pivot+1, n, target);
    }
    
    int bsearch_pivot(int A[], int n) {
        int lo = 0, hi = n-1;
        while(hi-lo > 1) {
            int mi = (lo+hi)/2;
            if(A[lo] < A[mi])
                lo = mi;
            else 
                hi = mi;
        }
        return lo;
    }
    
    int bsearch_target(int A[], int p, int n, int target) {
        int lo = p, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)/2;
            if(A[mi] < target)
                lo = mi+1;
            else if(A[mi] > target)
                hi = mi-1;
            else
                return mi;
        }
        return -1;
    }
};

