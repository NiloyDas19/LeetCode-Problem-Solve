//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/


/*

   Topic : BFS.

*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
    
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node* pre,*curr;
            if(sz){
                pre = q.front();
                q.pop();
                sz--;
                if(pre->left!=NULL) q.push(pre->left);
                if(pre->right!=NULL) q.push(pre->right);
            }
            while(sz--){
                curr = q.front();
                q.pop();
                pre->next = curr;
                pre = curr;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        
        return root;
    }
};