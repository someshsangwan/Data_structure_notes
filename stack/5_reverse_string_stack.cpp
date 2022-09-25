#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//it not a optimised approach but just application of stack;
string solve(string s){
    string ans="";
    stack<char>st;
    int n=s.size();
    for(int i=0;i<n;i++){
        st.push(s[i]);
    }
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s="somesh";
    cout<<solve(s)<<endl;
}