#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//problem_statement---
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, 
// where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
    bool check(int i,int j,int c,int m,int n,string word,vector<vector<char>>&board){
        if(c==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || word[c]!=board[i][j]){
            return false;
        } 
        board[i][j]='$';
        if(check(i+1,j,c+1,m,n,word,board) || check(i-1,j,c+1,m,n,word,board) ||check(i,j-1,c+1,m,n,word,board                ) || check(i,j+1,c+1,m,n,word,board)){
            return true;
        }
        board[i][j]=word[c];
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && check(i,j,0,m,n,word,board)){
                    return true;
                }
            }
        }
        return false;
        
    }