#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// here we are allowed to do at most 2 transaction  2 transaction matlb 2 bar buy krke 2 bar bechna 
// we will solve this question for at most K transaction --- hahahahahahhahahha;

int solve(int ind,int buy,int n,vector<int>&prices,int cap){
    if(cap==0){
        return 0;
    }
    if(ind==n){
        return 0;
    }
   
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+solve(ind+1,0,n,prices,cap),0+solve(ind+1,1,n,prices,cap));
    }
    else{
        profit=max(prices[ind]+solve(ind+1,1,n,prices,cap-1),0+solve(ind+1,0,n,prices,cap));//cap bechenge tb 1 decrease kr denge bcs buy to phle ho chuka hi tha ;
    }
    return profit;  
}
//isme hm bina 3_d dp ke kr skte h 
// buy ko hta skte h bcz hme pta hoga kb kharidega 
// capacity 2 transaction ki di h to use B=2*transaction =4 bna do
// ab tran%2==0 buy hoga else sell hoga 
/*
base me if(cap==B) return 0; ho jaega cap hmne 0 se start ki h bs 
if(cap%2==0){
        profit=max(-prices[ind]+solve(ind+1,0,n,prices,cap+1),0+solve(ind+1,1,n,prices,cap)); cap we will start from 0 na ;
    }
    else{
        profit=max(prices[ind]+solve(ind+1,1,n,prices,cap+1),0+solve(ind+1,0,n,prices,cap));//cap bechenge tb 1 decrease kr denge bcs buy to phle ho chuka hi tha ;
    }
*/
/*
tabulaion ho jaega ab to ezz -pzzz 
*/