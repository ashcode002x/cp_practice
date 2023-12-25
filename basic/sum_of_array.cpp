#include <bits/stdc++.h>
using namespace std;
//complexity
//time -> O(N)
//space -> O(n) n=size of array
int sumArray(int *a,int n){
    int sum = 0;
    return accumulate(a,a+n,sum);
}
int sumArray(vector<int>a){
    int sum = 0;
    return accumulate(a.begin(),a.end(),sum);
}
void printArray(vector<int>&v){
    for(auto it:v){
        cout<<it<<' ';
    }cout<<endl;
}
int main(){
    int a[]={1,2,3,4,5,6};
    int n = 6;
    cout<<sumArray(a,n)<<endl;
    vector<int>v = vector<int>(a,a+n);
    printArray(v);
    cout<<sumArray(v)<<endl;
    return 0;
}