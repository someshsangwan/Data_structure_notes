#include<bits/stdc++.h>
using namespace std;
#include<iostream>
// connected componenets means if all node are connected together it means there are 1 connected components(single component)
// there can be two question based on this concept first one is that count of connected components 
// second one is to store the component in a 2d vector ;

void dfs(int i,vector<int>&vis,vector<int>adj[]){
    vis[i]=1;
    for(auto it:adj[i]){
        if(vis[it]==0){
            dfs(it,vis,adj);
        }
    }
}
void dfs_store(int i,vector<int>&vis,vector<int>adj[],vector<int>&temp){
    temp.push_back(i);
    vis[i]=1;
    for(auto it:adj[i]){
        if(vis[it]==0){
            dfs_store(it,vis,adj,temp);
        }
    }

}
vector<vector<int>>store_component(int A,vector<int>adj[]){
    vector<vector<int>>ans;
    vector<int>temp;
    vector<int>vis(A+1,0);
    int ct=0;
    for(int i=1;i<=A;i++){
        if(vis[i]==0){
        dfs_store(i,vis,adj,temp);
        ans.push_back(temp);
        temp.clear();
        ct++;
    }
    }
    return ans;




}
int count_node(int A, vector<vector<int> > &B) {
    vector<int>adj[A+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]); // if we have given a 2d matrix as a node edges and we covert it into a adjacentry list 
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int>vis(A+1,0);
    int ct=0;
    for(int i=1;i<=A;i++){
        if(vis[i]==0){
        dfs(i,vis,adj);
        ct++;
    }
    }
    return ct;
}
int main(){
    int n,m;// here n is node and m is the no of edges;
    cout<<"enter no. of nodes and edges"<<endl;
    cin>>n>>m;
    vector<int>adj[n+1];
    cout<<"enter the connections"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;

}