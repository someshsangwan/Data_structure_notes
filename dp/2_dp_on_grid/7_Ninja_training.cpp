#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//probelm given that there are 3 types of training 1st,2nd,3rd he cant do same practice for 2 consecutive day;
/*
    2  9  3 
    11 2  21
    1  8  21    output will be 9+21+8=38;

*/

// day =n-1 last row , last=3;
int solve(int day,int last,vector<vector<int>>points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+solve(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}