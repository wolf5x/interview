// ???min
// O(n) ,b
// implementation can be simplified...
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n == 0) return false;
        int q = n-1;
        if(q >= 0 && A[0] == A[q]) {
            if(target == A[0])
                return true;
            while(q >= 0 && A[0] == A[q])
                q--;
        }
        if(q < 0)
            return false;
        int pivot = A[0] <= A[q] ? q : find_pivot(A, q+1);
        if(target >= A[0])
            return bs(A, pivot+1, target);
        else
            return bs(A+pivot+1, n-pivot-1, target);
    }
    
    int find_pivot(int A[], int n) {
        int lo = 0, hi = n-1;
        while(lo+1 < hi) {
            int mi = (lo+hi)>>1;
            if(A[mi] >= A[lo]) 
                lo = mi;
            else
                hi = mi;
        }
        return lo;
    }
    
    bool bs(int A[], int n, int target) {
        int lo = 0, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)>>1;
            if(A[mi] < target)
                lo = mi+1;
            else if(A[mi] > target)
                hi = mi-1;
            else    
                return true;
        }
        return false;
    }
};

