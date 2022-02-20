//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*
    It's a binary tree problem.
    To solve this problem I used here binary traversal.
    Time complexity --> O(n).
*/

TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == p || root == q || root == NULL)
        return root;
    TreeNode *left = helper(root->left, p, q);
    TreeNode *right = helper(root->right, p, q);
    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    if (right != NULL)
        return right;
    return NULL;
}
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return helper(root, p, q);
    }
};