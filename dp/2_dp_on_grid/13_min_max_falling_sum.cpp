#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//we have given a matrix N*N ,is filled with positive integer value , you have to find the minimum path from 0th row to N-1th row
// you can start from any column in 0th row and can end any column in last row;
// you can move diagonal left,diagonal right, Down ;
// probel is wher e we can start there are 4 choices to strating index -
// here we will start from bottom we will find solution for 
int solve(int i,int j,vector<vector<int>>arr,int n){
    if(j<0 || j>=n) return INT_MIN;
    if(i==0) return arr[0][j];
    int s=arr[i][j]+solve(i-1,j,arr,n);
    int ld=arr[i][j]+solve(i-1,j-1,arr,n);
    int rd=arr[i][j]+solve(i-1,j+1,arr,n);

    return max(s,max(ld,rd));
}
//memoization_code
int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        //int res=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=arr[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int s=INT_MAX;
                int ld=INT_MAX;
                int rd=INT_MAX;
                s=arr[i][j]+dp[i-1][j];
                if(j>=1) ld=arr[i][j]+dp[i-1][j-1];
                if(j+1<n) rd=arr[i][j]+dp[i-1][j+1];
                dp[i][j]=min(s,min(ld,rd));
            }
        }
        int res=dp[n-1][0];
        for(int i=1;i<n;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;
}


int main(){
    vector<vector<int>>arr;
    vector<int>temp1;
    temp1.push_back(1);
    temp1.push_back(2);
    temp1.push_back(10); 
    temp1.push_back(4);
    vector<int>temp2;
    temp2.push_back(100);
    temp2.push_back(3);
    temp2.push_back(2);
    temp2.push_back(1);
    vector<int>temp3;
    temp3.push_back(1);
    temp3.push_back(1);
    temp3.push_back(20);
    temp3.push_back(2);
    vector<int>temp4;
    temp4.push_back(1);
    temp4.push_back(2);
    temp4.push_back(2);
    temp4.push_back(1);
    arr.push_back(temp1);
    arr.push_back(temp2);
    arr.push_back(temp3);
    arr.push_back(temp4);
    int n=4;
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        res=max(res,solve(n-1,i,arr,n));
    }
    cout<<res<<endl;


}