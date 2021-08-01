//https://leetcode.com/problems/01-matrix/
/*
   Simple Graph problem.
   Solved this problem using BFS.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<int,int>> bfs;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(mat[i][j]==0) bfs.push({i,j});
        }
        
        while(!bfs.empty()){
            int i = bfs.front().first;
            int j = bfs.front().second;
            bfs.pop();
            if(i+1<n && mat[i+1][j]==1){
                mat[i+1][j] = 0;
                ans[i+1][j] = ans[i][j]+1;
                bfs.push({i+1,j});
            }
            if(i-1>=0 && mat[i-1][j]==1){
                mat[i-1][j] = 0;
                ans[i-1][j] = ans[i][j]+1;
                bfs.push({i-1,j});
            }
            if(j+1<m && mat[i][j+1]==1){
                mat[i][j+1] = 0;
                ans[i][j+1] = ans[i][j]+1;
                bfs.push({i,j+1});
            }
            if(j-1>=0 && mat[i][j-1]==1){
                mat[i][j-1] = 0;
                ans[i][j-1] = ans[i][j]+1;
                bfs.push({i,j-1});
            }
        }
        
        return ans;
    }
};