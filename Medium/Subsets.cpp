// https://leetcode.com/problems/subsets/

/*
  Used advanced backtracking and recursion to generate all the subsets.
*/

class Solution
{
    vector<vector<int>> all_subsets;
    void generate(vector<int> &subset, int i, vector<int> &nums)
    {
        if (i == nums.size())
        {
            all_subsets.push_back(subset);
            return;
        }

        generate(subset, i + 1, nums);
        subset.push_back(nums[i]);
        generate(subset, i + 1, nums);
        subset.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        generate(subset, 0, nums);
        return all_subsets;
    }
};