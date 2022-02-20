//https://leetcode.com/problems/max-consecutive-ones-iii/

/*
   I solved this problem using two-pointer approach.
   Time complexity--> O(n).
*/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int f_bit, start, end, ans;
        f_bit = start = end = ans = 0;
        while (end < nums.size())
        {
            if (nums[end] == 1)
            {
                end++;
            }
            else
            {
                if (f_bit < k)
                {
                    f_bit++;
                    end++;
                }
                else
                {
                    while (f_bit >= k)
                    {
                        if (nums[start] == 0)
                        {
                            f_bit--;
                        }
                        start++;
                    }
                }
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};