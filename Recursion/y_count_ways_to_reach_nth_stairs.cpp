#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*  you are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?*/
// approach is very simple in the last stair how we can reach , either we reach by one jump or by 2 jump;
// F(n)=f(n-1)+f(n-2);
    int climbStairs(int n) {
        if(n==1 || n==0){
            return n;
        }
        int dp[n+1]; //memoization to reduce time complexity;
        dp[0]=1;//we jump on 0th stair that is why we have 1 way 
        dp[1]=1;// to go first stair we have only one way we can jumb only one stair .
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
    int recursion(int n){
        if(n<0){         // for dp we can use memoization okay got it na ?
            return 0;
        }
        if(n==0){
            return 1;
        }
        return recursion(n-1)+recursion(n-2);
    }