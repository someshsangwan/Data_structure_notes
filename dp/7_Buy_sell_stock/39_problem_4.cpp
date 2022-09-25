#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// problem is very simple after selling u cant buy just after it 
// multiple transaction are allowed ;
//its very izz;
//just we have to small change // IND vs Wi - 2nd T20 india hug rhi h  16.3 over 115/6 ho gye kartik kuch kr skta h;
//{4,9,0,4,10} --- 4-9 , 0 wale ko kharid nhi skte , 4-10 output=11;
int solve(int ind,int buy,int n,vector<int>&prices){
    if(ind==n){
        return 0;
    }
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+solve(ind+1,0,n,prices),0+solve(ind+1,1,n,prices));
    }
    else{
        profit=max(prices[ind]+solve(ind+2,1,n,prices),0+solve(ind+1,0,n,prices)); //yha chnage hua bs jb bech rhe h wha ind+1 ki jagah +2 kr diye ;
    }
    return profit;  
}
