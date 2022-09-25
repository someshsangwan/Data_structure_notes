/*Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.*/
using namespace std;
#include<iostream>
#include<vector>
void check(int src ,vector<int>&vis,vector<int>adj[]){
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            check(it,vis,adj);
        }
    }
}
int motherVertex(int A, vector<vector<int> > &B) {
    vector<int>adj[A+1];
    int n=B.size();
    for(int i=0;i<n;i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<int>vis(n+1,0);
    int last=0;
    for(int i=1;i<=A;i++){
          if(!vis[i]){
              check(i,vis,adj);
              last=i;
          }
    }
    for(int i=0;i<=A;i++){
        vis[i]=0;
    }
    check(last,vis,adj);
    for(int i=1;i<=A;i++){
        if(vis[i]==0){
            return 0;
        }
    }
    return 1;

}