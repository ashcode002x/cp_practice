#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>>adj;
    Graph(int V):V(V){adj.resize(V);}
    void addEdge(int,int);
    bool isCyclic();
};

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isCyclic() {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int front = q.front();
                q.pop();

                if (visited[front]) {
                    return true;  // Graph contains a cycle
                }

                visited[front] = true;

                for (int it : adj[front]) {
                    if (!visited[it]) {
                        q.push(it);
                    }
                }
            }
        }
    }

    return false;  // Graph does not contain a cycle
}


int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
    return 0;
}