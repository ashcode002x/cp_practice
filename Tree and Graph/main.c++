#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>visited;
    void addEdge(int u,int v);
    void DFS(int src);
    void BFS(int src);
};
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::DFS(int src){
    visited[src]=true;
    cout<<src<<" ";
    list<int>::iterator i;
    for(i =adj[src].begin();i!=adj[src].end();i++){
        if(!visited[*i]){
            DFS(*i);
        }
    }
}

void Graph::BFS(int src){
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(visited[front])continue;
        cout<<front<<" ";
        visited[front]=true;
        list<int>::iterator i;
        for(i=adj[front].begin();i!=adj[front].end();i++){
            if(!visited[*i]){
                q.push(*i);
            }
        }
    }
}

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
    cout<<endl;

    g.BFS(0);//not work because visited map share same location so dfs update and bfs check if visited pass 
    cout<<endl;
    return 0;
}