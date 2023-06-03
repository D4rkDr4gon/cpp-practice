<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// algoritmo de dijkastra

typedef pair<int, int> pii;

vector<pii> adj[10001];
int dist[10001];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (pii v : adj[u])
        {
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
=======
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// algoritmo de dijkastra

typedef pair<int, int> pii;

vector<pii> adj[10001];
int dist[10001];

void dijkstra(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (pii v : adj[u])
        {
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
