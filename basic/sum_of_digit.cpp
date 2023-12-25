#include <bits/stdc++.h>
using namespace std;
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


int main(){
    int n;
    n=687;
    cout<<SumOfDigit(n)<<endl;//21
    n=12;
    cout<<SumOfDigit(n)<<endl;//3

    // iterative way
    n=987;
    int sum;
    for(sum=0;n>0;sum+=n%10,n/=10);
    cout<<sum<<endl;//24
    return 0;
}