#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. 
There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.


 0   1    0
 0   0    0
 0   0    1      output is 2;

*/



 
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool check(int& i,int& j,vector<vector<int>>& vis,int &n)
    {
        if( i < 0 || j < 0 || i>= n || j>=n || vis[i][j])
            return false;
        return true;
    }
    
    
    void dfs(int& i,int& j,vector<vector<int>>& grid,vector<vector<int>>& vis,queue<pair<int,int>>& q,int       &n)
    {
        vis[i][j] = 1;
        q.push({i,j});     // pushing all points of island 1 so that we can measure the distance from all                               //the points
        for(int k=0;k<4;k++)
        {
            int r = i+dx[k];
            int c = j+dy[k];
            if(check(r,c,vis,n) && grid[r][c])
            {
                dfs(r,c,grid,vis,q,n);
            }
        }
        
    }
    
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,queue<pair<int,int>>& q,int& n)
    {
        int step = -1;
        while(!q.empty())
        {
            step++;
            int sz = q.size();
            for(int a=0;a<sz;a++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                 for(int k=0;k<4;k++)
                {
                    int r = i+dx[k];
                    int c = j+dy[k];
                    if(check(r,c,vis,n) && grid[r][c] == 1)
                    {
                        return step;
                    }
                     
                    if(check(r,c,vis,n) && grid[r][c] == 0)
                    {
                        vis[r][c] = 1;
                        q.push({r,c});
                    }
                }
            }
        }
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n+1 , vector<int>(n+1,0));
        queue<pair<int,int>> q;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid,vis,q,n);  // first we are discovering our 1st island
                    flag = 1;
                    break;
                }  
            }
            if(flag == 1)
                break;
        }
        return bfs(grid,vis,q,n); // then measuring the distance between the first island and second                 //(unknown) island
    }
