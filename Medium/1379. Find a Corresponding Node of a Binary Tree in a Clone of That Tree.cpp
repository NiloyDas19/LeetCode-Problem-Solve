//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/


/*
   Topic : Binary  Tree, BFS , DFS.
*/


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned==NULL) return NULL;
        if(cloned->val==target->val) return cloned;
        TreeNode *left,*right;
        left  = getTargetCopy(original,cloned->left,target);
        right = getTargetCopy(original,cloned->right,target);
        return (left==NULL ? right : left);
    }
};