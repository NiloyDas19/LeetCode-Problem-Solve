// https://leetcode.com/problems/clone-graph/

/*
  Simple DFS problem.
*/

class Solution
{
    Node *dfs(Node *node, unordered_map<int, Node *> &visit)
    {
        Node *need = new Node(node->val);
        visit[node->val] = need;
        for (auto &it : node->neighbors)
        {
            Node *demo;
            if (visit.find(it->val) == visit.end())
            {
                demo = dfs(it, visit);
                need->neighbors.push_back(demo);
            }
            else
                need->neighbors.push_back(visit[it->val]);
        }
        return need;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        unordered_map<int, Node *> visit;
        return dfs(node, visit);
    }
};