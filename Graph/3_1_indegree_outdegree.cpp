#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// in this questiion we will see how to find indegree and outdegree of a graph;
// indegree means kistno se sign aa rha h 
// outdegree means kitno pe sign ja rha h
// we wiil see for directed graph;
// 1 base indexing;
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        vector<int>indegree(n+1);
        vector<int>outdegree(n+1);
        int x=trust.size();
        for(int i=0;i<x;i++){
            adj[trust[i][0]].push_back(trust[i][1]);
            
        }
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
                outdegree[i]++;
            }
        }