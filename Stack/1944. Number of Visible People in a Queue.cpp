// 1944. Number of Visible People in a Queue
// Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
// This is same as doing ngr
class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0;
        stack<int> s;
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            while (!s.empty() and nums[s.top()] <= nums[i])
                ans[s.top()]++, s.pop();

            if (!s.empty())
                ans[s.top()]++;

            s.push(i);
        }

        return ans;
    }
};