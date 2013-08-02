// 15min
// O(n)
class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> need(128, 0);
        vector<int> has(128, 0);
        int lack = 0;
        for(int i = 0; i < T.length(); i++) {
            if(need[T[i]] == 0)
                lack++;
            need[T[i]]++;
        }
        int ansl = -1, ansp = -1;
        int head = 0, tail = 0;
        while(tail < S.length()) {
            has[S[tail]]++;
            if(has[S[tail]] == need[S[tail]])
                lack--;
            tail++;
            while(head < tail && has[S[head]] > need[S[head]])
                has[S[head++]]--;
            if(lack == 0)
                if(ansl < 0 || ansl > tail-head)
                    ansl = tail-head, ansp = tail-ansl;
        }
        return ansl < 0 ? "" : S.substr(ansp, ansl);
    }
};

