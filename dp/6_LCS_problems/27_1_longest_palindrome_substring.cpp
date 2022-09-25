#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// problem is simple given a string and we have to find longest palindrome substring
// here LCS concept does not work ;
// take an example :- S="caba"  make reverse S'="abac" longest common substring="aba" yes it is working
// another exaplme : S = "abacdfgdcaba", S'="abacdgfdcaba"; LCsubsting="abacd" but final answer is "aba"

// lets try with 2 pointer approach ;
    string longestPalindrome(string s) {
        int maxi=0;
        int startingIndex=0;
        int n=s.size();
        for(int k=0;k<n;k++){
            //odd
            int i=k;
            int j=k;
            while(i>=0 && j<n && s[i]==s[j]){
                int len=j-i+1;
                if(len>maxi){
                    maxi=len;
                    startingIndex=i;
                }
                i--;
                j++;
            }
            //even
            i=k;
            j=k+1;
            while(i>=0 && j<n && s[i]==s[j]){
                int len=j-i+1;
                if(len>maxi){
                    maxi=len;
                    startingIndex=i;
                }
                i--;
                j++;
            }
        }
        string ans;
        ans=s.substr(startingIndex,maxi);
        return ans;
    }
 