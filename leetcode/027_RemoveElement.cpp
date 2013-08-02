// 2min, 1AC
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for(int i = n-1; i >= 0; i--) {
            if(A[i] == elem) {
                A[i] = A[--n];
            }
        }
        return n;
    }
};

