// 16min, 1WA
// O(1) extra space
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; i++) {
            if(A[i] <= 0 || A[i] > n) {
                A[i] = -1;
                continue;
            }
            int t = -1, p = i;
            while(p >= 0 && p < n && A[p] != p+1) {
                int next = A[p]-1;
                A[p] = t;
                t = next+1; // first WA here
                p = next;
            }
        }
        for(int i = 0; i < n; i++) {
            if(A[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};

