/*
 * Candy
 * http://oj.leetcode.com/problems/candy/
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */

/*
 * O(n) time, O(1) space
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        int ans = 0;
        int last = 0;
        for (int i = 0; i < n; ) {
            int j = i; 
            while((j < n-1 && ratings[j] < ratings[j+1]) || j == n-1)
                j++;
            if (j != i) {
                ans += (1+(j-i))*(j-i)/2;
                last = j-i;
                i = j;
            }
            while(j < n-1 && ratings[j] > ratings[j+1])
                j++;
            if (j != i) {
                ans += max(last+1, j-i+1);
                ans += (2+j-i)*(j-i-1)/2;
                last = 0;
                i = j;
            }
            while(j < n-1 && ratings[j] == ratings[j+1])
                j++;
            if (j != i) {
                ans += last+1;
                ans += j-i-1;
                last = 0;
                i = j;
            }
        }
        return ans;
    }
};
