// https://leetcode.com/problems/network-delay-time/


/*
	Topic : Dijkstra Algorithm.

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto &it:times){
            graph[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n+1,INT32_MAX);
        queue<int>q;
        q.push(k);
        dis[k] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &it:graph[u]){
                int neighbour = it.first;
                int cost = it.second;
                if(dis[neighbour]>dis[u]+cost){
                    dis[neighbour] = dis[u]+cost;
                    q.push(neighbour);
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT32_MAX) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};