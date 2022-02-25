class Solution
{
    // https://leetcode.com/problems/compare-version-numbers/

    /*
       Easy Approach.
       TC : O(n).
       SC : O(1).

    */

public:
    int compareVersion(string version1, string version2)
    {
        int i, j, first, second;
        i = j = first = second = 0;
        while (1)
        {
            if (i >= version1.size() && j >= version2.size())
            {
                break;
            }
            string s1, s2;
            while (i < version1.size() && version1[i] != '.')
            {
                s1.push_back(version1[i]);
                i++;
            }
            while (j < version2.size() && version2[j] != '.')
            {
                s2.push_back(version2[j]);
                j++;
            }
            i++;
            j++;
            first = second = 0;
            if (s1.size() > 0)
                first = stoi(s1);
            if (s2.size() > 0)
                second = stoi(s2);
            if (first == second)
                continue;
            if (first > second)
                return 1;
            else
                return -1;
        }
        return 0;
    }
};