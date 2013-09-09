/**
 * Given an array containing positive and negtive numbers.
 * Sort the array so that all negtive numbers are in the 
 * first half of the array and the positives in the second.
 * The relative order of all the negtive numbers should be
 * stable. The same to the positives.
 * *Don't use extra space.*
 * eg. Given [3,-9,8,-1,-2,4,5], return [-9,-1,-2,3,8,4,5]
 */
void stable01Sorting(vector<int> &num)
{
    int n = num.size();
    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i += k<<1) {
            int lo = i, mi = min(n,i+k), up = min(n, i+k+k);
            if (mi == up) 
                continue;
            int one = mi, zero = mi-1;
            while(one > lo && num[one-1] > 0)
                one--;
            while(zero < up && num[zero] < 0)
                zero++;
            reverse(num, one, mi);
            reverse(num, mi, zero);
            reverse(num, one, zero);
        }
    }
}

void reverse(vector<int> &num, int lo, int up)
{
    for (int i = (up-lo)/2-1; i >= 0; i--)
        swap(num[lo+i], num[up-1-i]);
}

