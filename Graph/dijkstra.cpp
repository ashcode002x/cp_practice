#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,vector<pair<int,int>>>adj;
    void addEdge(int,int,int);
    void dijkstra(int,int,vector<int>&,vector<bool>&);
};

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
void Graph::dijkstra(int src,int curr_dist,vector<int>&dist,vector<bool>&visited){
    queue<pair<int,int>>q;
    q.push({src,curr_dist});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        dist[front.first]=min(front.second,dist[front.first]);
        visited[front.first]=true;
        for(auto next:adj[front.first]){
            if(!visited[next.first]){
                q.push({next.first,next.second+front.second});
            }
        }
    }
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
    vector<int>dist(vertex,INT_MAX);
    vector<bool>visited(vertex,false);
    g.dijkstra(0,0,dist,visited);
    for (int i = 0; i < vertex; ++i) {
        cout << dist[i] << endl;
    }
    return 0;
}