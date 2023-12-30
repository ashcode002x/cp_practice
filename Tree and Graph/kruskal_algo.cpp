#include <bits/stdc++.h>
using namespace std;


// error 


class Graph {
public:
    vector<vector<pair<int, int>>> adj;

    Graph(int v) { adj.resize(v); }

    void addEdge(int, int, int);
    void kruskal();
    static bool compare(pair<int, int> a, pair<int, int> b);
    int find(int x,vector<int>&parent){
        if(x == parent[x])return x;
        return find(parent[x],parent);
    }
    void Union(int a,int b,vector<int>&parent){
        int x = find(a,parent);
        int y = find(b,parent);
        parent[y]=x;
    }

};

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

bool Graph::compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void Graph::kruskal() {
    vector<int> parent(adj.size());
    for (int i = 0; i < adj.size(); i++) {
        parent[i] = i;
    }

    for (int i = 0; i < adj.size(); i++) {
        sort(adj[i].begin(), adj[i].end(), compare);
        for (int j = 0; j < adj[i].size(); j++) {
            auto it = adj[i][j];
            if (find(it.first, parent) != find(it.second, parent)) {
                cout << i << " -> " << it.first << " = " << it.second << endl;
                Union(it.first, it.second, parent);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.kruskal();
    return 0;
}
