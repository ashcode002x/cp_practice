#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<int,vector<pair<int,int>>>adj;
    void addEdge(int,int,int);
    vector<int> bellman_ford(int);
};

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
    // adj[v].push_back({u,w});
}

vector<int> Graph::bellman_ford(int V){
    vector<int>dist(V,INT_MAX);
    vector<bool>visited(V,false);
    queue<pair<int,int>>q;

    // First Pass
    q.push({0,0});
    dist[0]=0;
    visited[0]=true;
    
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        visited[front.first]=true;
        int prev_wt = front.second;
        
        for(auto it:adj[front.first]){
            if(dist[it.first]>prev_wt+it.second){
                dist[it.first]=prev_wt+it.second;
            }
            if(!visited[it.first]){
                q.push({it.first,dist[it.first]});
                visited[it.first]=true;
            }
        }
    }

    // Reset visited array
    visited = vector<bool>(V,false);

    // Second Pass
    q.push({0,0});
    dist[0]=0;
    visited[0]=true;

    while(!q.empty()){
        auto front=q.front();
        q.pop();
        visited[front.first]=true;
        int prev_wt=front.second;
        for(auto it:adj[front.first]){
            if(dist[it.first]>dist[front.first]+it.second){
                cout<<"negative weight cycle";
                return {};
            }
            if(!visited[it.first]){
                q.push({it.first, dist[it.first]});
                visited[it.first]=true;
            }
        }
    }

    return dist;
}

int main(){
    Graph g;
    int vertex = 6;
    // g.addEdge(0,1,4);
    // g.addEdge(0,2,4);
    // g.addEdge(1,2,2);
    // g.addEdge(2,3,3);
    // g.addEdge(2,4,1);
    // g.addEdge(2,5,6);
    // g.addEdge(3,5,2);
    // g.addEdge(4,5,3);

    g.addEdge(0,1,5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    g.addEdge(2,4,1);
    g.addEdge(4,3,1);
    g.addEdge(3,5,2);
    g.addEdge(5,4,3);
    /*this is negative weight cycle*/

    for(auto it:g.bellman_ford(vertex)){
        cout<<it<<endl;
    }
    return 0;
}
