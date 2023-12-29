#include <bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&parent){
    if(parent[x]==x)return x;
    return find(parent[x],parent);
}

void Union(int x,int y,vector<int>&parent){
    int f1 = find(x,parent);
    int f2 = find(y,parent);
    if(f1==f2)return;
    parent[f1]=min(f1,f2);
    parent[f2]=min(f1,f2);
    return;
}
int main(){
    vector<int>parent(8);
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
    Union(0,1,parent);
    Union(2,7,parent);
    Union(3,6,parent);
    cout<<(find(0,parent)==find(2,parent))<<endl;
    Union(0,7,parent);
    cout<<(find(0,parent)==find(2,parent))<<endl;
    for(int i:parent){
        cout<<i<<' ';
    }cout<<endl;
    return 0;
}