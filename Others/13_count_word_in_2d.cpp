#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Find the number of occurrences of a given search word in  a 2d-Array of characters 
// where the word can go up, down, left, right and around 90 degree bends.
// Input: 
// R = 4, C = 5
// mat = {{S,N,B,S,N},
//        {B,A,K,E,A},
//        {B,K,B,B,K},
//        {S,E,B,S,E}}
// target = SNAKES
// Output:
// 3

class Solution{
    public:
    void dfs(vector<vector<char>>&mat,string target,int i, int j,int &res ,int ind){
        if(i<0 || j<0 || i==mat.size() || j==mat[0].size() || mat[i][j]!=target[ind]){
            return;
        }
        if(ind==target.length()-1){
            res++;
            return;
        }
        char temp=mat[i][j];
        mat[i][j]='*';
        dfs(mat,target,i+1,j,res,ind+1);
        dfs(mat,target,i-1,j,res,ind+1);
        dfs(mat,target,i,j+1,res,ind+1);
        dfs(mat,target,i,j-1,res,ind+1);
        mat[i][j]=temp;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int res=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==target[0]){
                    dfs(mat,target,i,j,res,0);
                }
            }
        }
        return res;
    }
};