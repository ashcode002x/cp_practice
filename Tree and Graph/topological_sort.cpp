#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<vector<pair<int,int>>>adj;
    Graph(int v){adj.resize(v);}
    void addEdge(int,int,int);
    void topologicalSortUtil(int,bool[],stack<int>&);
    void topologicalSort();
};
void Graph::addEdge(int u,int v,int w=0){
    adj[u].push_back({v,w});
}
void Graph::topologicalSortUtil(int src,bool visited[],stack<int>&st){
    visited[src]=true;
    for(auto it:adj[src]){
        if(!visited[it.first])topologicalSortUtil(it.first,visited,st);
    }
    st.push(src);
}
void Graph::topologicalSort(){
    bool visited[adj.size()];
    stack<int>st;
    for(int i=0;i<adj.size();i++){
        if(!visited[i])topologicalSortUtil(i,visited,st);
    }
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }cout<<endl;
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topologicalSort();
    return 0;
}