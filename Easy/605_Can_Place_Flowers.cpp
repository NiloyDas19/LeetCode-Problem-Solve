// https://leetcode.com/problems/can-place-flowers/

/*
  It's an easy problem.
  TC : O(n)
  SC : O(n)
*/

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        vector<int> check;
        check.push_back(0);
        for (int i = 0; i < flowerbed.size(); i++)
            check.push_back(flowerbed[i]);
        check.push_back(0);
        for (int i = 1; i < check.size() - 1; i++)
        {
            if (check[i] == 0 && n > 0 && check[i - 1] == 0 && check[i + 1] == 0)
                check[i] = 1, n--;
        }
        return n == 0;
    }
};