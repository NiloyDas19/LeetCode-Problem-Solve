//https://leetcode.com/problems/break-a-palindrome/

/*
 It's an easy-medium question.
 Checked all possible cases to make the string lexicographical small.
 TC -> O(26*n^2*logn).
*/

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() <= 1)
            return "";

        for (int i = 0; i < palindrome.size(); i++)
        {
            if (palindrome[i] == 'a')
                continue;
            string cpy, rcpy;
            cpy = palindrome;
            for (char j = 'a'; j < palindrome[i]; j++)
            {
                cpy[i] = j;
                rcpy = cpy;
                reverse(rcpy.begin(), rcpy.end());
                if (cpy != rcpy)
                    return cpy;
            }
        }

        for (int i = palindrome.size() - 1; i >= 0; i--)
        {
            string cpy, rcpy;
            cpy = palindrome;
            for (char j = palindrome[i]; j <= 'z'; j++)
            {
                cpy[i] = j;
                rcpy = cpy;
                reverse(rcpy.begin(), rcpy.end());
                if (cpy != rcpy)
                    return cpy;
            }
        }

        return "";
    }
};