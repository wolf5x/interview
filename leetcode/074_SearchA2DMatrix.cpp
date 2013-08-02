// 5min, 1RE
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m-1, row = -1;
        while(lo <= hi) {
            int mi = (lo+hi)>>1;
            if(matrix[mi][0] <= target)
                row = mi, lo = mi+1;
            else 
                hi = mi-1;
        }
        if(row < 0) // RE: missed this
            return false;
        lo = 0, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)>>1;
            if(matrix[row][mi] < target)
                lo = mi+1;
            else if(matrix[row][mi] > target)
                hi = mi-1;
            else
                return true;
        }
        return false;
    }
};

