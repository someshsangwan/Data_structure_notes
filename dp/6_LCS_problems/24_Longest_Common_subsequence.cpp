#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//given two string find longest common subsequence out of them 
//Example s1="adebc"  s2="dcadb";
// output will be - length print krni h->3 ->adb ;


//memoization method is very easy to understand ;
    int LCS(int i,int j,string s1, string s2,vector<vector<int>>&dp){
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+LCS(i-1,j-1,s1,s2,dp);
    }
    else{
        return dp[i][j]=max(LCS(i-1,j,s1,s2,dp),LCS(i,j-1,s1,s2,dp));
    }
    }
int main(){
    string s1="adebc";
    string s2="dcadb";
    int m=s1.size();
    int n=s2.size();
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // return LCS(m-1,n-1,s1,s2,dp);
    //tabulation - base is i<0 & j<0 but dp array me hm likh nhi skte to hm index shift krenge 
    // if hm lcs me sidha m,n bheje to condition 
    // base i==0 || j==0 then return 0;
    // if(s1[i-1]==s2[j-1]) return dp[i][j]=.......
    //same here;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){//shifting of index;
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        cout<<dp[m][n]<<endl;
}