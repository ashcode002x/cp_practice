#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<pair<int, int>>> adj;
    void addEdge(int, int, int);
    void BFS(int);
};
void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
}
void Graph::BFS(int src){
    queue<pair<int,int>>q;
    int V=adj.size();
    q.push({src,0});
    unordered_set<int>st;
    st.insert(src);
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int curr = front.first;
        int wt = front.second;
        for(auto it:adj[curr]){
            if(!st.count(it.first)){
                dist[it.first]=min(dist[it.first],it.second+wt);
                q.push({it.first, dist[it.first]});
            }
        }
    }
    for(int i:dist){
        cout<<i<<' ';
    }cout<<endl;
}

int main(){
    int V = 9;
    Graph g;
    g.adj.resize(V);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 7, 1);
    g.addEdge(1, 7, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 0); 
    g.addEdge(2, 5, 0); 
    g.addEdge(2, 8, 1); 
    g.addEdge(3, 4, 1); 
    g.addEdge(3, 5, 1); 
    g.addEdge(4, 5, 1); 
    g.addEdge(5, 6, 1); 
    g.addEdge(6, 7, 1); 
    g.addEdge(7, 8, 1); 
    g.BFS(0);

    return 0;
}