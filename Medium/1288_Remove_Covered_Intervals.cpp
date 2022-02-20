// https://leetcode.com/problems/remove-covered-intervals/

/*

  Solved this problem using Sorting.
  TC : O(n^2).
  SC : O(1).

*/

static int speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] == -1 && intervals[i][1] == -1)
                continue;
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j][0] == -1 && intervals[j][1] == -1)
                    continue;
                if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])
                {
                    intervals[j][0] = intervals[j][1] = -1;
                }
            }
            ans++;
        }
        return ans;
    }
};