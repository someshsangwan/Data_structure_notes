#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// prints node who is making cycle;
    bool dfs(vector<vector<int>>& graph,vector<bool> &visited,int node,vector<bool> &dfsvisited,
            vector<bool> &cycle){
        visited[node] = true;
        dfsvisited[node] =  true;
        for(auto nbr:graph[node]){
            if(!visited[nbr]){
                if(dfs(graph,visited,nbr,dfsvisited,cycle)){
                    return cycle[node] = true;
                }
        }
            else if(visited[nbr] && dfsvisited[nbr]){
                return cycle[node] = true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<bool> dfsvisited(n,false);
        vector<bool> cycle(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited,i,cycle,dfsvisited);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(cycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }