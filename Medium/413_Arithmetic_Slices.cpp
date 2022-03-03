// https://leetcode.com/problems/arithmetic-slices/

/*
 Easy Medium Problem.
 TC : O(n)
 SC : O(n)
*/

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int ans = 0, cnt = 1, diff = nums[1] - nums[0];
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] - nums[i] == diff)
            {
                cnt++;
            }
            else
            {
                if (cnt >= 3)
                {
                    int a = cnt - 2;
                    ans += (a * (a + 1)) / 2;
                    cnt = 2;
                }
                diff = nums[i + 1] - nums[i];
            }
        }
        if (cnt >= 3)
        {
            int a = cnt - 2;
            ans += (a * (a + 1)) / 2;
        }
        return ans;
    }
};