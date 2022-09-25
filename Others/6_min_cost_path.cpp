#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*problem statement -:
You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

1) If you follow what is written in the cell then you can move freely.
2) But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.

*/
//EXAMPLE 
// Example Input
// Input:1
                      
//  A = 3
//  B = 3
//  C = ["RRR","DDD","UUU"]
// ouput 1: R->R->R->D(1)->D  output 1;
// Input:2

//  A = 1
//  B = 4
//  C = ["LLLL"]

// output:- R(1)->R(1)->R(1)->L => output-3;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
int solve(int A, int B, vector<string> &C) {
    string s="URDL";
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    vector<vector<int>>dist(A,vector<int>(B,INT_MAX-1));
    q.push({0,{0,0}});
    dist[0][0]=0;
    while(!q.empty()){
      
        int i=q.top().second.first;
        int j=q.top().second.second;
        q.pop();
        if(i==A-1 && j==B-1){
            return dist[i][j];
        }
        for(int k=0;k<4;k++){
        int x=i+xx[k];
        int y=j+yy[k];
        int cost=dist[i][j];
        if(s[k]!=C[i][j]){
            cost++;
        }
        if(x>=0 && y>=0 && x<A && y<B && dist[x][y]>cost){
            dist[x][y]=cost;
            q.push({cost,{x,y}});
        }
       }
    }
    return dist[A-1][B-1];
     
}
