#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water. isme adjacent bola h matlab 4 direction  diagonallu nhi dekhna h hmko;
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


*/
 void bfs(int i,int j,int m ,int n,vector<vector<char>>& grid,vector<vector<int>>& vis){
       vector<vector<int>>dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(auto it:dirs){
            int row=i+it[0];
            int col=j+it[1];
            if(row<m && row>=0 && col>=0 && col<n){
                if(grid[row][col]=='1' && vis[row][col]==0){
                    q.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int ans=0;
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,m,n,grid,vis);
                        ans++; 
                }
  
            }
        }
        return ans;
        
 
        
    }