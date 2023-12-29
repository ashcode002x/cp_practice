#include <bits/stdc++.h>
using namespace std;

//complexity
//time -> O(V^3)
//space -> O(V^2)
class Graph
{
public:
    vector<vector<pair<int, int>>> adj;
    void addEdge(int, int, int);
    vector<vector<int>> floyd_warshall(int);
    void print(vector<vector<int>>);
};

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
}

vector<vector<int>> Graph::floyd_warshall(int V)
{
    vector<vector<int>> dist = vector<vector<int>>(V, vector<int>(V, INT_MAX));

    // Initialize diagonal elements to 0
    for (int i = 0; i < V; ++i)
    {
        dist[i][i] = 0;
    }

    // Update distances based on edge weights
    for (int i = 0; i < V; ++i)
    {
        for (auto &neighbor : adj[i])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            dist[i][v] = weight;
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

void Graph::print(vector<vector<int>> dist)
{
    cout << "/**********starting**********/" << endl;
    for (auto i : dist)
    {
        for (auto j : i)
        {
            if (j == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    Graph g;
    int V;
    V = 5;
    g.adj.resize(V);
    g.addEdge(0, 0, 0);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 1, 0);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 2, 0);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 3, 0);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 3, 4);
    g.addEdge(4, 4, 0);
    g.print(g.floyd_warshall(V));
    cout << "finish" << endl;
    return 0;
}
