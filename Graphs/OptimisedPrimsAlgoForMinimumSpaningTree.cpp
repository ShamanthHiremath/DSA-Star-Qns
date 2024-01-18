#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //Stores minmost element as top/front
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    int src = 1;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (mst[u])
            continue;

        mst[u] = true;

        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;

            if (!mst[v] && w < pq_key[v])
            {
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ansMST;
    for (int i = src + 1; i <= n; i++)
    {
        ansMST.push_back({{parent[i], i}, pq_key[i]});
    }

    return ansMST;
}