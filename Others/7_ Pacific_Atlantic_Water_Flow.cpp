#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights 
where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, 
south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. 
Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from 
cell (ri, ci) to both the Pacific and Atlantic oceans.

*/

//exapmle- 1 see jpg file ;
// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

//question smjh me aaya ki - koi esa point dhundo in the graph ki hm us points se dono ocean me ja ske ;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
class Solution {
public:
    void bfs(vector<vector<int>>&h,queue<pair<int,int>>&q,vector<vector<int>>&ocean,int m,int n){
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            ocean[i][j]=1;
            for(int k=0;k<4;k++){
                int x=i+xx[k];
                int y=j+yy[k];
                if(x>=0 && y>=0 && x<m && y<n && h[x][y]>=h[i][j] && ocean[x][y]==0){
                    q.push({x,y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        queue<pair<int,int>>q1;
        queue<pair<int,int>>q2;
        for(int i=0;i<m;i++){
            q1.push({i,0});
        }
        for(int i=0;i<n;i++){
            q1.push({0,i});
        }
        bfs(heights,q1,pacific,m,n);
        for(int i=0;i<m;i++){
            q2.push({i,n-1});
        }
        for(int i=0;i<n;i++){
            q2.push({m-1,i});
        }
        bfs(heights,q2,atlantic,m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        
        
    }
};