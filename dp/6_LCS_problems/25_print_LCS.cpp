#include<bits/stdc++.h>
using namespace std;
#include<iostream>

//print logest common subsequence , given two string ;
int main(){
    string s1="adebc";
    string s2="dcadb";
    int m=s1.size();
    int n=s2.size();
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
        }
        int size=dp[m][n]; //size of answer string;
        string ans="";
        for(int i=0;i<size;i++){
            ans+='$';
        }
        int i=m;
        int j=n;
         
        int index=size-1;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans[index]=s1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        cout<<ans<<endl;

}