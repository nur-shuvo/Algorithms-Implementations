/*

  |---|
        |---|
          |---|
          |------|
          |--------|
                      |----|

// So basically we need to find the gaps.
// Need to sort all the intervals by start time.

*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        vector<pair<int, int>> intervals;

        for (auto ele : schedule) {
            for (auto it : ele)
                intervals.push_back({ it.start, it.end });
        }

        sort(intervals.begin(), intervals.end());

        int prev_last = intervals[0].second;
        for (int i = 1; i < intervals.size(); i++) {
            int cur_start = intervals[i].first;
            int cur_last = intervals[i].second;
            if (cur_start > prev_last && (cur_start - prev_last) >= 1) {
                res.push_back(Interval(prev_last, cur_start));
            }
            prev_last = max(prev_last, cur_last); // note
        }
        return res;
    }
};

/*

Optimization
[nur.shuvo]
1. N log K -> if using priority queue of size k, maintained as the first element of any employee is the smallest in that intervals.
2. What if use merge sort for that problem "Merge K sorted list"? -> N log K for sorting

*/