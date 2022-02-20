//https://leetcode.com/problems/maximal-rectangle/

/*
  Solved this problem using next lower element approach.
  It's a hard problem.
  TC --> O(n^2)
*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> leftmost(n, 0), rightmost(n, 0);
        stack<int> st, st1;
        for (int i = 0; i < n; i++)
        {
            int ind = -1;
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
                ind = st.top();
            st.push(i);
            leftmost[i] = ind + 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int ind = n;
            while (!st1.empty() && heights[st1.top()] >= heights[i])
            {
                st1.pop();
            }
            if (!st1.empty())
                ind = st1.top();
            st1.push(i);
            rightmost[i] = ind - 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a = heights[i] * (rightmost[i] - leftmost[i] + 1);
            ans = max(a, ans);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();

        vector<int> dp(col);
        for (int i = 0; i < col; i++)
            dp[i] = matrix[0][i] - '0';
        int ans = largestRectangleArea(dp);
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '0')
                    dp[j] = 0;
                else
                    dp[j]++;
            }
            ans = max(ans, largestRectangleArea(dp));
        }
        return ans;
    }
};