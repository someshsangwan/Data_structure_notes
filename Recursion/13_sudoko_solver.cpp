/*
sudoko is 9*9 board game
there are total 9 3*3 small boxes -


fill all the sudoko with the following rule-
1) the digit 1-9 should have once in a row;
2) the digit 1-9 should have once in a column;
3) the digit 1-9 should have once in a 3*3 board that are total 9 in sudoko;

// hey please go to sudoko_solver.png file ans see that png file you will get more idea about that----
thanks --

*/
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool isvalid(vector<vector<char>>&board,int row,int col, char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }
            if(board[i][col]==c){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                return false;
            }
             
        }
     return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                        
                    }
                    return false;
                }
                 
            }
        }
        return true;
    }

    // main function
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }