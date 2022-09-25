#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//bhai ye question interview me puch lia to mza aa jaega pura 1 round ka time nikal dunga usko baklu  bnaake-- huehue hueheu
/*probel statement -
you have N-queen and N*N chess board your task is to placed N queen at chees board with given condition -
1- every row should have only 1 queen.
2- every column should have  only 1 queen.
3-no two queens attack each other. there are 8 position where 2 queen can attack - up,down,left,right and 4 diagonal direction.


return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
example n=4;
output=there are two possible answer we can nake 2 combination-
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Q means we pplaced queen at that place;

in this example first  we wiil place Q at 0th row and make a recursion call and check it will be right combination or not
next we place Q at 1st row and --------------------------------------------------------------------------
next we place Q at 2nd row and -------------------------------------------------------------------------
next we place Q at 3rd row and =----------------------------------------------------------------------
 if we find right combination in all of them we store them ------------------

 to check is this right position to placed Q we dont need check all direction bcz we are placing Q left to right na column wise;
 so we need to check only 3 direction one is left and two other north west , south west got it na ?
when we return from recursion call we will remove all queen that we placed during recursion --- backtracking bolti h ye sb 
*/
// dont afraid  to see code its very easy --
bool issafe(int row,int col,vector<string>&board,int n){
        int duprow=row;
        int dupcol=col;
        //1st direction north-west --both will decrease-
        while(col>=0 && row>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        // now 2 direction left only col will decrease
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        // now 3rd direction south -west, row increse && col decrease
        row=duprow;
        col=dupcol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
        
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');  
        for(int i=0;i<n;i++){
            board[i]=s;   // first we fill all placed with '.';
        }
        solve(0,board,ans,n);
        return ans;
        
    }










int main(){

}