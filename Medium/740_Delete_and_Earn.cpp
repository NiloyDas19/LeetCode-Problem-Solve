// https://leetcode.com/problems/delete-and-earn/

/*

  Dp problem
  TC : O(n)
  SC : O(n)

*/

class Solution
{
public:
  int deleteAndEarn(vector<int> &nums)
  {
    vector<int> fre(10005, 0);
    vector<int> dp(10005, 0);
    for (auto &it : nums)
      fre[it]++;
    dp[1] = fre[1];
    for (int i = 2; i < 10005; i++)
      dp[i] = max(dp[i - 1], i * fre[i] + dp[i - 2]);
    return dp[10004];
  }
};