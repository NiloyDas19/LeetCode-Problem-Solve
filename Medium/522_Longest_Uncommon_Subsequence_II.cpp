//https://leetcode.com/problems/longest-uncommon-subsequence-ii/

/*
   Although it's a medium level problem. Solved this problem using sorting.
*/

class Solution
{
    bool issubsequence(string small, string big)
    {
        int i = 0, j = 0;
        while (i < small.size() && j < big.size())
        {
            if (small[i] == big[j])
                i++;
            j++;
        }
        return i == small.size();
    }

public:
    int findLUSlength(vector<string> &strs)
    {
        sort(strs.begin(), strs.end(), [](string a, string b)
             { return a.size() > b.size(); });
        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = 0; j < strs.size() && strs[j].size() >= strs[i].size(); j++)
            {
                if (i != j && issubsequence(strs[i], strs[j]))
                    goto ch;
            }
            return strs[i].size();
        ch:;
        }
        return -1;
    }
};