//https://leetcode.com/problems/shortest-path-in-binary-matrix/


/*
	Topic : BFS.
*/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> eight = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        int n = grid.size();
        if(grid[0][0]||grid[n-1][n-1]) return -1;
        vector<vector<bool>> visit(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                visit[x][y] = true;
                if(x==n-1 && y==n-1) {
                    ans++;
                    return ans;
                }
                
                for(auto &it:eight){
                    int x1 = x+it.first;
                    int y1 = y+it.second;
                    if(x1<0 || y1<0 || x1>=n || y1>=n) continue;
                    if(visit[x1][y1] || grid[x1][y1]) continue;
                    visit[x1][y1] = true;
                    q.push({x1,y1});
                }
            }
            ans++;
        }
        return -1;
    }
};