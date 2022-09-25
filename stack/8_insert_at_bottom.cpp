#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&s,int x,int ct,int n){
    if(ct==n){
        s.push(x);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,x,ct+1,n);
    s.push(val);

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
    s.push(8);
    int x=87;
    int ct=0;
    int n=s.size();
    insert(s,x,ct,n);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}