#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//we have given a stack of integer you have to delete middle element of stack;
void solve(stack<int>&s,int n,int ct){
    if(ct==n/2){
        s.pop();
        return;
    }
    int data=s.top();
    s.pop();
    solve(s,n,ct+1);
    s.push(data);
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    int n=s.size();
    int ct=0;
    solve(s,n,ct);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}