//same component me lie krenge if they have same parent -- logic in minimum spanning tree
//  no need of adjacentry list , just we need a linear data structure to store wt,u,v and sort list on the base of weight(wt);
// suru me sb ke parent sb hi honge , jb parent alag alag honge to unhe merge krenge agar same honge to ignore mar denge ;
#include<bits/stdc++.h>
using namespace std;
#include<iostream>
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
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
int minweight(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int>rank(n);
    makeset(n,rank,parent);
    int minweight=0;
    for(int i=0;i<edges.size();i++){
        int u=findparent(parent,edges[i][0]);
        int v=findparent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            minweight+=wt;
            union_set(u,v,parent,rank);
        }
    }
    return minweight;

}