#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>>adj;
    Graph(int V):V(V){adj.resize(V);}
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    bool CycleDetection(){
        vector<int> inDegree(V, 0);

        // Calculate in-degrees of all vertices
        for (int i = 0; i < V; ++i) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;

        // Enqueue vertices with in-degree 0
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // Count of visited vertices

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            count++;

            for (auto it : adj[front]) {
                if (--inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Check if all vertices were visited
        cout<<count<<' '<<V<<endl;
        if(count != V)cout<<"cycle is present"<<endl;
        else cout<<"cycle is not present"<<endl;
        return count!=V;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);
    g.addEdge(2, 3);
    // g.addEdge(3, 3);
    cout<<g.CycleDetection()<<endl;
    return 0;
}