// https://leetcode.com/problems/min-cost-to-connect-all-points/

/*
    This a MST problem.
    Implement this by Krushkal's algorithm.
*/

class Solution
{
public:
    int parent[1005], sz[1005];
    void make(int v)
    {
        parent[v] = v;
        sz[v] = 1;
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        for (int i = 1; i <= n; i++)
            make(i);
        vector<pair<int, pair<int, int>>> edge_cost;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edge_cost.push_back({cost, {i + 1, j + 1}});
            }
        }

        sort(edge_cost.begin(), edge_cost.end());

        int ans = 0;
        for (int i = 0; i < edge_cost.size(); i++)
        {
            int c = edge_cost[i].first;
            int u = edge_cost[i].second.first;
            int v = edge_cost[i].second.second;

            u = find(u);
            v = find(v);
            if (u != v)
            {
                ans += c;
                Union(u, v);
            }
        }

        return ans;
    }
};