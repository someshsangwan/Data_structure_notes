#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// here multiple transaction are allowed but if you buy a stock then first you have to sell this stock before buying another stock ----
//here we will use dp;
// here we have 2 option either we can buy or not buy ; if buy==1 it means we can buy 
//ind =0;buy=1
int solve(int ind,int buy,int n,vector<int>&prices,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;

    if(buy){
        profit=max(-prices[ind]+solve(ind+1,0,n,prices,dp),0+solve(ind+1,1,n,prices,dp));
    }
    else{
        profit=max(prices[ind]+solve(ind+1,1,n,prices,dp),0+solve(ind+1,0,n,prices,dp));
    }
    return dp[ind][buy]=profit;  
}
//dp to tum use kr loge hi   dp[N][2];
//Tabulation_method
int solve_2(vector<int>prices){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));//bcz base condition is at ind==n ;so that we make it n+1;
    dp[n][0]=dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);

            }
            else{
                profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];


}
int main(){
    int prices[]={7,1,5,3,6,4};
    int n=6;
    vector<int>temp;
    for(int i=0;i<n;i++){
        temp.push_back(prices[i]);
    }
    vector<vector<int>>dp(n,vector<int>(2,-1));
    cout<<solve(0,1,n,temp,dp)<<endl;

}