// 630. Course Schedule III
// Link:https://leetcode.com/problems/course-schedule-iii/

/*
The first apporach I thought of is usnig backtracking.
But it is giving TLE.

Now, the next approach is using max heap.
Why?
Because, in the sorted courses by lastDay, we can pick the the course taking the maximum duration till now and remove it to replace it with shorter time duration courses.
Thereby maximising the courses intake we can have.
*/

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(begin(courses), end(courses), [](const vector<int> &v1, const vector<int> &v2)
             { return v1[1] < v2[1]; });
        priority_queue<int> maxHeap;
        int ans = 0, sum = 0;

        for (auto course : courses)
        {
            sum += course[0];
            maxHeap.push(course[0]);

            if (sum > course[1])
                sum -= maxHeap.top(), maxHeap.pop();
        }

        return maxHeap.size();
    }
};