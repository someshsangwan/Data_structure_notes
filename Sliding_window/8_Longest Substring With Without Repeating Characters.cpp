#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h> 
/*
given a string s, find the length of the longest substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

*/
// its similar to the last problem in this question we have to find th longest substring with all unique character(No repeating char)
// last problem was that kth unique character;

    int lengthOfLongestSubstring(string s) {
    unordered_map<char,int>mp;
    int res=0;
    int i=0;
    int n=s.size();
    if(n==0){
        return 0;
    }
    int j=0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            res=max(res,j-i+1);
        }
        if(mp.size()<j-i+1){
            while(mp.size()!=j-i+1){
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

