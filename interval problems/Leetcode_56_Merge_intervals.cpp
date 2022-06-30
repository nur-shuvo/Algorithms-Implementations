/*

|----------------|
  |----|
          |----|

How many meetings start bfore the earliest ending time of a meeting.

*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for (auto& interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0, ans = 0, countOfStartedMeeting = 0;
        while (i < n && j < n) {
            if (start[i] < end[j]) {
                countOfStartedMeeting++;
                i++;
            }
            else {
                countOfStartedMeeting--;
                j++;
            }
            ans = max(countOfStartedMeeting, ans);
        }
        return ans;
    }
};