/*
You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.
*/
/*
 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]

output [0, 1, 2, 2, 3, 4, 6, 9, 10] ;

*/
using namespace std;
#include<iostream>
#include<bits/stdc++.h>
 
class Node{
    public:
    int data;
    int i;
    int j;
    Node(int data,int row,int col){
        this->data=data;
        i=row;
        j=col;
    }
};
class comp{
    public:
    bool operator()(Node*a,Node*b){
    return a->data > b->data;
}
};

vector<int>merge(vector<vector<int>>&arr,int k){
    priority_queue<Node*,vector<Node*>,comp>minheap;
    for(int i=0;i<k;i++){
        Node* temp=new Node(arr[i][0],i,0);
        minheap.push(temp);
    }
    vector<int>ans;
    while(minheap.size()>0){
        Node* temp=minheap.top();
        ans.push_back(temp->data);
        minheap.pop();
        int i=temp->i;
        int j=temp->j;
        if(j+1<arr[i].size()){
            Node* next=new Node(arr[i][j+1],i,j+1);
            minheap.push(next);
        }

    }
    return ans;

}

