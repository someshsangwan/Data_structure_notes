#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//its a good problem bois  // important  for OA as well as Interview
// problem - given  2 string make a minimum size string in which both string are present as a subsequence ;
// max size will be s1+s2;
// we have to find minimum size ;

// example s1="brute"   s2="groot"   ans string="bgruoote"
// len puche to bahut ezz=> len of supersequence if =len(s1)+len(s2)-Lcs(s1,s2);

//same h bhai print lcs jaisa bs isme hr case me ans me add krna hoga ;
   string shortestCommonSupersequence(string s1, string s2) {
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
        int i=m;
        int j=n;
        string ans="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }