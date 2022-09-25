#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 //just small change h 
int main(){
    string s1="adebc";
    string s2="dcadb";
    int m=s1.size();
    int n=s2.size();
    int ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){//shifting of index;
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        cout<<ans<<endl;
}