// 5min, 1WA
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int p = 0;
        for(int i = 0; i < n; i++) {
            if(p > 0 && A[i] == A[p-1]) {
                continue;
            }
            A[p++] = A[i];
        }
        return p;
    }
};

