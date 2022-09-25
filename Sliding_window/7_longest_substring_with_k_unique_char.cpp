#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. 
If there is no possible substring then print -1

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.




*/
    int longestKSubstr(string s, int k) {
    unordered_map<char,int>mp;
    int res=-1;
    int i=0;
    int n=s.size();
    int j=0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==k){
            res=max(res,j-i+1);
        }
        if(mp.size()>k){
            while(mp.size()!=k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return res;
    }