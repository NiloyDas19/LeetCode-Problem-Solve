// https://leetcode.com/problems/sudoku-solver/

/*
 It's a hard level problem but interesting.
 Solved this problem using Recursion and Backtracking technique.

*/

class Solution
{
    bool isValid(vector<vector<char>> &board, int i, int j, char ch)
    {
        int n = i / 3 * 3;
        int m = j / 3 * 3;

        for (int k = 0; k < 9; k++)
        {
            if (board[i][k] == ch)
                return false;
            if (board[k][j] == ch)
                return false;
            if (board[n + k / 3][m + k % 3] == ch)
                return false;
        }

        return true;
    }

    bool check(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, i, j, ch))
                        {
                            board[i][j] = ch;

                            if (check(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        check(board);
    }
};