/*
 * 56. Merge Intervals
 * Medium
 * 
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * Example 2:
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * Accepted
 * 279,939
 * Submissions
 * 820,503
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool issmaller(struct Interval &a, struct Interval &b)
{
    return a.start < b.start;
}

/*
 * 一次AC，用时1h
 * Runtime: 12 ms, faster than 53.81% of C++ online submissions for Merge Intervals.
 */
class Solution1 {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        vector<Interval>::iterator head, tail;
        sort(intervals.begin(), intervals.end(), issmaller);
        for (head = intervals.begin(), tail = head + 1; head != intervals.end(); tail++) {
            if (tail != intervals.end() && head->end >= tail->start) {
                head->end = (head->end > tail->end ? head->end : tail->end);
            } else {
                res.push_back(*head);
                head = tail;
            }
        }
        return res;
    }
};

void print(vector<Interval> v)
{
    vector<Interval>::iterator iter;
    cout << "{";
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << "{" << iter->start << "," << iter->end << "}";
        cout << (iter + 1 == v.end() ? "" : ",");
    }
    cout << "}" << endl;
}

int main()
{
    Solution1 s;
    vector<Interval> res;
    vector<Interval> intervals1 = {{2,6},{1,3},{8,10},{15,18}};
    cout << "before merge: ";
    print(intervals1);
    res = s.merge(intervals1);
    cout << "after merge: ";
    print(res);

    return 0;
}
