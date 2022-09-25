#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* problem statement-
 we have done one question in graph that problem was bipartitte graph , if you are not familiar with graph skip this question pls;
 in bipartite problem , the graph can be colored with  2 colors such that no two adjacent vertices of the graph are 
 colored with the same color. 

but in this problem we have M color -   2<=M<=....
if it is possible to colored graph such that no two adjacent vertices of graph are colored with the  same  color return 1 else 
return 0;

t.c-O(n^m) m is the no . of  colors and n is the no. of nodes;*/

bool issafe(int node,int color[],bool graph[101][101],int n,int col){
    for(int i=0;i<n;i++){
        if(i!=node && graph[i][node]==1/*edge dekh rhe*/&& color[i]==col){
            return false;
        }
        
    }
    return true;
}
bool solve(int node,int color[],int m,int n, bool graph[101][101]){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(issafe(node,color,graph,n,i)){
            color[node]=i;
            if(solve(node+1,color,m,n,graph)){
                return true;
            }
            color[node]=0;//if not possible to aate time 0 bna denge
        }
        
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n]={0};
    if(solve(0,color,m,n,graph)){
        return true;
    }
    else{
        return false;
    }
}





