//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


/*
	Topic : DFS + DP.
*/




class Solution {
public:
    int m,n;
    vector<pair<int,int>> move = {{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>> &matrix,vector<vector<int>> &dp,int pre,int i,int j){
        if(i>=m || i<0 || j>=n || j<0 || matrix[i][j] <= pre) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maX = 0;
        for(auto &[x,y]:move){
            int row = x + i;
            int col = y + j;
            int val = dfs(matrix,dp,matrix[i][j],row,col);
            maX = max(maX,val);
        }
        
        return dp[i][j] = maX+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = dfs(matrix,dp,INT32_MIN,i,j);
                ans = max(ans,val);
            }
        }
        
        return ans;
    }
};