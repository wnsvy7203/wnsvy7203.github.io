// 48ms

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E, ans;
vector<pair<int, int>> edges[10001];
void init()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[from].push_back({cost, to});
        edges[to].push_back({cost, from});
    }
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pque;
bool visited[10001];
void prim()
{
    pque.push({0, 1});
    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (visited[node])
            continue;
        
        visited[node] = 1;
        ans += cost;

        for (int i = 0; i < edges[node].size(); i++)
        {
            int next_cost = edges[node][i].first;
            int next_node = edges[node][i].second;

            if (!visited[next_node])
                pque.push({next_cost, next_node});
        }
    }
    
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    prim();
}