#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<queue>
// generally we use heap as a stl in c++;
//priority_queue;
//max heap=  priority_queue<int>pq;
//min heap= priority_queue<int,vector<int>,greater<int>>pq;
int main(){
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>pq;
    p.push(4);
    p.push(3);
    p.push(1);
    p.push(2);
    cout<<"max_heap"<<endl;
    cout<<p.top()<<endl;
    cout<<p.size()<<endl;
    p.pop();
    cout<<p.top()<<endl;
    cout<<"min heap"<<endl;
    pq.push(4);
    pq.push(3);
    pq.push(1);
    pq.push(2);
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;



}

