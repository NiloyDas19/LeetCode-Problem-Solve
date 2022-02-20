// https://leetcode.com/problems/number-of-matching-subsequences/


/*
   Explain : 
   s = "abcde"
   words = ["a","bb","acd","ace"]

   a --->  a  acd  ace
   b --->  bb
   c --->
   d --->
   e --->

   Iterate and check the first char and earse it from the corresponding word .
   if the length of the word is zero then count one else again store the word .

*/

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<char, vector<string>> m;

        for (auto &word : words)
        {
            m[word[0]].push_back(word);
        }

        int cnt = 0;
        for (auto ltr : s)
        {
            if (m.count(ltr))
            {
                vector<string> vec(m[ltr]);
                m.erase(ltr);
                for (auto v : vec)
                {
                    if (v.size() == 1)
                        cnt++;
                    else
                    {
                        m[v[1]].push_back(v.substr(1));
                    }
                }
            }
        }
        return cnt;
    }
};