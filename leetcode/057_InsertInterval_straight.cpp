// 10min, 1AC
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
        vector<Interval> ans;
        int n = intervals.size();
        bool ins = false;
        for(int i = 0; i < n; i++) {
            if(newInterval.start <= intervals[i].end 
                    && newInterval.end >= intervals[i].start) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                if(!ins && intervals[i].start > newInterval.end) {
                    ins = true;
                    ans.push_back(newInterval);
                }
                ans.push_back(intervals[i]);
            }
        }
        if(!ins)
            ans.push_back(newInterval);
        return ans;
    }
};

