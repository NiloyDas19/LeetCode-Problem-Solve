//https://leetcode.com/problems/candy/

/*

  I solved this problem by greedy approach. 
  Just look at the code and you can easily understand what i did there.
  Time complexity O(n)  n = number of children.

*/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int sz = ratings.size();
        if (sz == 1)
            return 1;

        vector<int> candies(sz, 1);
        for (int i = sz - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                candies[i] = candies[i + 1] + 1;
        }
        for (int i = 1; i < sz; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] = max(candies[i], candies[i - 1] + 1);
        }
        int cad = 0;
        cad = accumulate(candies.begin(), candies.end(), cad);
        return cad;
    }
};