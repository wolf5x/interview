// 10min, 1AC (See Permuations.cpp)
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> start(num);
        do {
            next_permutation(num);
            ans.push_back(num);
        } while(!vector_equal(num, start));
        return ans;
    }
    
    void next_permutation(vector<int> &num) {
        if(num.size() == 0)
            return;
        int peak = num.size()-1;
        while(peak > 0 && num[peak] <= num[peak-1])
            peak--;
        if(peak > 0) {
            int rep = num.size()-1;
            while(rep > peak && num[rep] <= num[peak-1])
                rep--;
            swap(num[peak-1], num[rep]);
        }
        reverse(num.begin()+peak, num.end());
    }
    
    bool vector_equal(vector<int> &x, vector<int> &y) {
        for(int i = 0; i < x.size(); i++)
            if(x[i] != y[i])
                return false;
        return true;
    }
};

