// 15min, 1AC
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    class Comparator{
    public:
        bool operator()(const Interval &x, const Interval &y) const {
            return x.start < y.start;
        }
    };
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        int n = intervals.size();
        if (n==0)
            return ans;
        sort(intervals.begin(), intervals.end(), Comparator());
        for(int p = 0; p < n; ) {
            int q = p+1;
            int end = intervals[p].end;
            while (q < n && intervals[q].start <= end) {
                end = max(end, intervals[q].end);
                q++;
            }
            ans.push_back(Interval(intervals[p].start, end));
            p = q;
        }
        return ans;
    }
};

