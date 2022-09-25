#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute force make a another stack;
void insert_at_bottom(stack<int>&s,int num){
    // have done before;
}
void reverse_stack(stack<int>&s){
    if(s.size()==0){
        return;
    }
    int num=s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s,num);

}