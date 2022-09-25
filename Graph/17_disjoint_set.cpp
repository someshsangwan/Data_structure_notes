#include<bits/stdc++.h>
using namespace std;
#include<iostream>
int findparent(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findparent(parent,parent[node]);
}

void union_set(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        //both have same rank;
        parent[v]=u; //koi bhi bna do pr jisko bnao uski rank badha do maa ki chut;
        rank[u]++;
    }
}
void makeset(int n,vector<int>&rank,vector<int>&parent){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }

}
int main(){
    int n;
    vector<int>rank(n);
    vector<int>parent(n);
    makeset(n,rank,parent);

}