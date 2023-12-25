#include <bits/stdc++.h>
using namespace std;
//complexity
//time -> O(N)
//space -> O(1)
inline void reverse(int *arr, int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-1-i]);
    }
}
//complexity
//time -> O(N)
//space -> O(N)
inline void reverseRecursion(int *arr,int start,int end){
    if(start>=end)return;
    swap(arr[start],arr[end]);
    reverseRecursion(arr,start+1,end-1);
}
inline void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n = 5;
    // reverse(arr,n); // 5 4 3 2 1

    reverseRecursion(arr,0,n-1); // 5 4 3 2 1
    printArray(arr,n);
    return 0;
}