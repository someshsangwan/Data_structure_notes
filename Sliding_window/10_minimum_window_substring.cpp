#include<bits/stdc++.h>
using namespace std;
#include<iostream>
//The Hardest Problem Of sliding window if u are able to solve this problem then u can do any problem related to sliding window;
// //problem statement 

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s 
// such that every character in t (including duplicates) is included in the window. If there is no such substring, 
// return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

 string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int res=INT_MAX;
        int ct=mp.size();
        int i=0;
        int j=0;
        int start=0;
        while(j<s.size()){
             
            if(mp.find(s[j])!=mp.end()){
                if(mp[s[j]]==1){
                    mp[s[j]]--;
                    ct--;
                }
                else{
                    mp[s[j]]--;
                }
            }
            if(ct==0){
                while(ct==0){
                    if(mp.find(s[i])==mp.end()){
                       i++;
                      continue;             
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        ct++;
                        if(res>j-i+1){
                            res=j-i+1;
                            start=i;
                        }
                        i++;
                        break;
                    }
                    i++;
                }  
            }
            j++;
        }
        cout<<start<<" "<<res<<" ";
     return res==INT_MAX?"":s.substr(start,res);
        
        
    }