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

int main(){
    string s;
    s="aabaa";
    bool palen = checkPalindrome(s);
    if(palen)cout<<"String is palindrome "<<s<<endl;
    else cout<<"String is not palindrome "<<s<<endl;

    s = "baosf";
    palen = checkPalindrome(s);
    if(palen)cout<<"String is palindrome "<<s<<endl;
    else cout<<"String is not palindrome "<<s<<endl;

    return 0;
}