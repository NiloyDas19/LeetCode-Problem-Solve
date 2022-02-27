// https://leetcode.com/problems/maximum-width-of-binary-tree/

/*

 It's a binary tree problem.
 Solved this problem using BFS.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        long long ans = 1;
        while (!q.empty())
        {
            long long sz = q.size();
            vector<long long> store;
            while (sz--)
            {
                auto it = q.front();
                q.pop();
                long long val = it.second;
                TreeNode *temp = it.first;
                if (temp == NULL)
                {
                    continue;
                }
                if (temp->left != NULL)
                {
                    q.push({temp->left, 2LL * val - 1});
                    store.push_back(2LL * val - 1);
                }
                if (temp->right != NULL)
                {
                    q.push({temp->right, 2LL * val});
                    store.push_back(2LL * val);
                }
            }
            long long sz1 = store.size();
            if (sz1 > 0)
            {
                ans = max(ans, store[sz1 - 1] - store[0] + 1);
            }
        }
        return (int)ans;
    }
};