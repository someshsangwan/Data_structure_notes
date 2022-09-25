#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
problem statement -
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

example-
Input: s = "aab"

Output: [["a","a","b"],["aa","b"]]
*/
// approach we will partition at every index and check ki left wala palindrome h ya nhi-
    bool ispalindrome(string s ,int start,int last){
        while(start<=last){
            if(s[start]!=s[last]){
                return false;
            }
            start++;
            last--;
        }
        return true;
    }
    void func(int index,string s,vector<string>&path,vector<vector<string>>&res)     {
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                func(i+1,s,path,res);
                path.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        func(0,s,path,res);
        return res;
    }