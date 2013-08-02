// 15min, 1WA
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int peak = num.size()-1;
        for(; peak > 0 && num[peak-1] >= num[peak]; peak--);
        if(peak > 0) {
            int replace = num.size()-1;
            for(; replace > peak && num[peak-1] >= num[replace];
                    replace--);
            swap(num[peak-1], num[replace]);
        }
        reverse(num.begin()+peak, num.end());
    }
};

