#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

*/
    bool is_valid(int x,int y, int n,vector<vector<int>>&grid,vector<vector<int>>&visited)
{
if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && !visited[x][y])
return true;
return false;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
if(0==n-1 && 0==n-1)return 1;
vector<vector<int>>visited(n,vector<int>(n,false));
queue<pair<pair<int,int>,int>>q;
q.push({{0,0},1});
visited[0][0]=true;
int ans=0;
while(!q.empty())
{
pair<int,int>p=q.front().first;
int length=q.front().second;
q.pop();
int xx=p.first;
int yy=p.second;
int ax[8]={-1,0,1,1,1,0,-1,-1};
int ay[8]={1,1,1,0,-1,-1,-1,0};
for(int i=0;i<8;i++)
{
int x=ax[i]+xx;
int y=ay[i]+yy;
if(x==n-1 && y==n-1)return length+1;
if(is_valid(x,y,n,grid,visited))
{
visited[x][y]=true;
q.push({{x,y},length+1});
}
}
}
return -1;
        
    }