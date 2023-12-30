#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<pair<int,int>>>adj;
    Graph(int v){adj.resize(v);}
    void addEdge(int,int,int);
    void prims();
};

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
void Graph::prims(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    bool visited[adj.size()];
    pq.push({0,0});
    vector<int>dist(adj.size(),INT_MAX);
    vector<pair<int,int>>ans(adj.size());
    ans[0]=make_pair(0,0);
    while(!pq.empty()){
        auto top = pq.top();//src weight
        pq.pop();
        visited[top.first]=true;
        for(auto it:adj[top.first]){
            if(!visited[it.first]){
                if(it.second+top.second<dist[it.first]){
                    dist[it.first]=it.second+top.second;
                    ans[it.first]={top.first,it.first};
                    pq.push({it.first,dist[it.first]});
                }
            }
        }
    }
    for(auto it:dist){
        cout<<it<<' ';
    }cout<<endl;
    for(int i=1;i<adj.size();i++){
        auto it = ans[i];
        int wt = dist[it.first]!=INT_MAX?(dist[it.second]-dist[it.first]):dist[it.second];
        cout<<it.first<<" -> "<<it.second<<" = "<<wt<<endl;
    }
}
Graph convertGridToGraph(vector<vector<int>>&grid){
    Graph ans(grid.size());
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid.size();j++){
            if(grid[i][j]!=0)ans.addEdge(i,j,grid[i][j]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>grid = 
    { { 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 } };
    Graph g=convertGridToGraph(grid);
    g.prims();
}