// 20min
// O(n)
class Solution {
public:
    void sortColors(int A[], int n) {
        int cnt[3] = {};
        for(int i = 0; i < n; i++)
            cnt[A[i]]++;
        int range[4] = {0, cnt[0], cnt[0]+cnt[1], cnt[0]+cnt[1]+cnt[2]};
        int pos[3] = {range[0], range[1], range[2]};
        for(int i = 0; i < n; i++) {
            while(i < range[A[i]] || i >= range[A[i]+1]) {
                int to = A[i];
                swap(A[i], A[pos[to]]);
                pos[to]++;
            }
        }
    }
};

