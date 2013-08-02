// 20min, 1AC
// egg-ache binary search
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
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        int lo = 0, hi = n-1;
        int sp = n, ep = -1;
        while(lo <= hi) {
            int mi = (lo+hi)/2;
            if (newInterval.start <= intervals[mi].end)
                sp = mi, hi = mi-1;
            else
                lo = mi+1;
        }
        lo = 0, hi = n-1;
        while(lo <= hi) {
            int mi = (lo+hi)/2;
            if (newInterval.end >= intervals[mi].start)
                ep = mi, lo = mi+1;
            else
                hi = mi-1;
        }
        vector<Interval> ans;
        ans.insert(ans.end(), intervals.begin(), intervals.begin()+sp);
        if(sp <= ep) {
            ans.push_back(Interval(min(intervals[sp].start, newInterval.start),
                    max(intervals[ep].end, newInterval.end)));
        } else {
            ans.push_back(newInterval);
            ans.insert(ans.end(), intervals.begin()+sp, intervals.begin()+ep+1);
        }
        ans.insert(ans.end(), intervals.begin()+ep+1, intervals.end());
        return ans;
    }
};

