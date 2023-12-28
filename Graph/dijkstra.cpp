#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,vector<pair<int,int>>>adj;
    void addEdge(int,int,int);
    void dijkstra(int);
};

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
void Graph::dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int V = adj.size();
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    vector<bool>visited(V,false);
    pq.push({src,0});
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int curr = top.first;
        int wt = top.second;
        visited[curr]=true;
        for(auto it:adj[curr]){
            if(!visited[it.first]){
                dist[it.first]=min(it.second+wt,dist[it.first]);
                pq.push({it.first,dist[it.first]});
            }
        }
    }
    for(int i:dist){
        cout<<i<<' ';
    }cout<<endl;
}

int main(){
    Graph g;
    int vertex = 6;
    g.addEdge(0,1,4);
    g.addEdge(0,2,4);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(2,4,1);
    g.addEdge(2,5,6);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);
    g.dijkstra(0);
    return 0;
}