// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
  BST Problem.
  TC: O(n). n--> number of nodes.
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
    int cnt = 0, ans;
    void helper(TreeNode *root)
    {
        if (root == NULL)
            return;
        helper(root->left);
        cnt--;
        if (cnt == 0)
            ans = root->val;
        helper(root->right);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        cnt = k;
        helper(root);
        return ans;
    }
};