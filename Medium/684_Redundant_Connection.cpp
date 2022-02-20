//https://leetcode.com/problems/redundant-connection/

/*
   Find those edge which makes the circle.
*/

class Solution
{
    bool dfs(vector<bool> visit, vector<vector<int>> &graph, int source, int target)
    {
        if (source == target)
            return true;
        visit[source] = true;
        for (auto src : graph[source])
        {
            if (visit[src] == false)
                if (dfs(visit, graph, src, target))
                    return true;
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int sz = edges.size();
        vector<vector<int>> graph(sz + 1);
        vector<int> ans(2);
        for (int i = 0; i < sz; i++)
        {
            vector<bool> visit(sz + 1, false);
            if (dfs(visit, graph, edges[i][0], edges[i][1]))
            {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
                break;
            }
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return ans;
    }
};