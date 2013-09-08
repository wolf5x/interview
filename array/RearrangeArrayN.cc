/**
 * Given two arrays of length N, each is a permutaion of 
 * numbers from 0 to N-1.
 * Use the only operation allowed: swap the first and 
 * arbitary kth element, to transform the first array to
 * the second.
 * eg. given [0,1,2] and [0,2,1]
 * One way is: [0,1,2]->[2,1,0]->[2,0,1]->[0,2,1]
 */ 
//---------- Header --------------
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//---------- Solution ------------
class Solution {
public:
    vector<int> solve(vector<int> from, vector<int> to) {
        vector<int> ans;
        unordered_map<int,int> pos;
        int n = from.size();
        if (n == 0)
            return ans;
        for (int i = 0; i < n; i++)
            pos[to[i]] = i;
        int p = 1;
        while(p < n) {
            while(pos[from[0]] != 0 && pos[from[pos[from[0]]]] != 0) {
                ans.push_back(pos[from[0]]);
                swap(from[0], from[pos[from[0]]]);
            }
            while(p < n && (pos[from[p]] == p || pos[from[p]] == 0))
                p++;
            if (p < n) {
                ans.push_back(p);
                swap(from[0], from[p]);
            }
        }
        if (pos[from[0]] != 0) {
            ans.push_back(pos[from[0]]);
            swap(from[0], from[pos[from[0]]]);
        }
        return ans;
    }
};

//---------- Checker -------------

class Checker {
public:
    void showVector(vector<int> &v) {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << (i<v.size()-1?" ":"\n");
    }
    
    void testOne(vector<int> v1, vector<int> v2) {
        vector<int> ans = Solution().solve(v1,v2);
        cout << "0: ";
        showVector(v1);
        for(int i = 0; i < ans.size(); i++){
            swap(v1[0], v1[ans[i]]);
            cout << i+1 << ": ";
            showVector(v1);
        }
        cout << "to ";
        showVector(v2);
        cout << "\n";
    }

    void check() {
        testOne(vector<int>({0,1,2}), vector<int>({0,2,1}));
        testOne(vector<int>({0,1,2,3,4}), vector<int>({0,1,2,3,4}));
        testOne(vector<int>({0,2,1,4,3}), vector<int>({0,1,2,3,4}));
        testOne(vector<int>({4,2,3,0,1}), vector<int>({4,3,2,1,0}));
        testOne(vector<int>({5,1,4,3,0,2}), vector<int>({0,1,2,3,4,5}));
        testOne(vector<int>({0,1,2,3,4,5}), vector<int>({5,1,4,3,0,2}));
    }
};

int main() {
    Checker().check();
    return 0;
}


