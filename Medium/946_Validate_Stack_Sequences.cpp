//https://leetcode.com/problems/validate-stack-sequences/

/*
  The problem is based on stack.
  TC: O(n)
  SC: O(n)
*/


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i,j;
        i = j = 0;
        stack<int> p;
        while(i<pushed.size() && j<popped.size()){
            if(pushed[i]!=popped[j]){
                p.push(pushed[i]);
                i++;
            }
            else{
                p.push(pushed[i]);
                i++;
                while(p.size()>0 && j<popped.size() && p.top()==popped[j]){
                    p.pop();
                    j++;
                }
            }
        }
        
        return p.empty();
    }
};