#include <bits/stdc++.h>
using namespace std;

//complexity
//time -> O(N)
//space -> O(1)
bool checkPalindrome(string &s){
    bool palen = true;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])palen=false;
    }
    return palen;
}

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

//complexity
//time -> O(logN)
//space -> O(1)
inline int SumOfDigit(int n){
    int ans = 0;
    while(n>0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}


inline void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}

int main(){
    
    return 0;
}