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
private:
    static bool compare(Interval i, Interval j) {
        return i.start < j.start;
    }
    
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        for (int i = 0; i < intervals.size(); i++) {
            if (minHeap.empty() || minHeap.top() > intervals[i].start) {
                minHeap.push(intervals[i].end);
            } else {
                minHeap.pop();
                minHeap.push(intervals[i].end);
            }
        }
        return minHeap.size();
    }
};