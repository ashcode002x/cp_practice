#include <bits/stdc++.h>
using namespace std;

/*******check palindrome********* */

//complexity
//time -> O(N)
//space -> O(1)
inline bool checkPalindrome(string &s){
    bool palen = true;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])palen=false;
    }
    return palen;
}

/**********reverse of array**********/
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

/**********sum of array**********/
//complexity
//time -> O(N)
//space -> O(n) n=size of array
inline int sumArray(int *a,int n){
    int sum = 0;
    return accumulate(a,a+n,sum);
}
inline int sumArray(vector<int>a){
    int sum = 0;
    return accumulate(a.begin(),a.end(),sum);
}

/********sum of digit********/
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

/**********minimum and maximum of array**********/
//complexity
//time -> O(logN)
//space -> O(1)
inline int getMin(vector<int>arr){
    return *min(arr.begin(),arr.end());
}
inline int getMax(vector<int>arr){
    return *max(arr.begin(),arr.end());
}

// ********prefix sum ********

//complexity
//time -> O(logN)
//space -> O(1)
inline vector<int>prefixSum(vector<int>&v){
    vector<int>ans;
    int curr_sum = 0;
    for(int i=0;i<v.size();i++){
        curr_sum+=v[i];
        ans.push_back(curr_sum);
    }
    return ans;
}

/**********print array**********/
//complexity
//time -> O(N)
//space -> O(1)
inline void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}
inline void printArray(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    vector<int>ans = prefixSum(arr);
    printArray(ans);
    
    return 0;
}