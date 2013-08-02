// 7min
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = -1, j = 0, c = 0;
        while(j < n) {
            if(i == -1 || A[j] != A[i]) {
                c = 1;
                A[++i] = A[j++];
            } else if(A[j] == A[i] && c < 2) {
                c++;
                A[++i] = A[j++];
            } else {
                j++;
            }
        }
        return i+1;
    }
};

