// 20min, 2WA
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        stk.push(-1);
        int n = height.size();
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            int h = i<n ? height[i] : -1;
            while(stk.top()>=0 && height[stk.top()] > h) {
                int t = height[stk.top()];
                stk.pop();
                ans = max(ans, t*(i-stk.top()-1));
            }
            stk.push(i);
        }
        return ans;
    }
};

