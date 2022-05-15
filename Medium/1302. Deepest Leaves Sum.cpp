//https://leetcode.com/problems/deepest-leaves-sum/

/*
   Topic : BFS.
*/


class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int a = 0;
            while(sz--){
                a+=q.front()->val;
                if(q.front()->left!=NULL) q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front()->right);
                q.pop();
            }
            if(a) ans = a;
        }
        return ans;
    }
};