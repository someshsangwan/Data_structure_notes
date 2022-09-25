#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* problem statement
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in 
the matrix represents that  it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents 
that rat can be travel through it.

/* jha pe possible,  multitraversal jaisa kuch ho recursion dimag me aa jana chahiye;

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

// time complexity = 4^m*n, aux space- o(m*n) max depth of recrusion call-

*/
    void solve(int i,int j,vector<vector<int>> &m, int n,int di[],int dj[],vector<vector<int>>&vis,vector<string>&ans,string move){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        string dir="DLRU"; //hme sort me print krwana h so that ---
        for(int ind=0;ind<4;ind++){
            int nexti=i+di[ind];
            int nextj=j+dj[ind];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj]&& m[nexti][nextj]==1){
                vis[i][j]=1;
                solve(nexti,nextj,m,n,di,dj,vis,ans,move+dir[ind]);
                vis[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        //we will check first Down ,Left,right,up-DLRU bcz we have to print in lexiographically
        vector<vector<int>>vis(n,vector<int>(n,0));
        int di[]={+1,0,0,-1};// why we are using di , dj bcz hme 4 loop ki jrurat na padegi iske bad 
        int dj[]={0,-1,+1,0};
        if(m[0][0]==1){
            solve(0,0,m,n,di,dj,vis,ans,"");
        }
        return ans;
    }




int main(){

}