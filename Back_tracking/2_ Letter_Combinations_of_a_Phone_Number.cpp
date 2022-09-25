#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

void solve(int index,string digits,string output,vector<string>&ans,unordered_map<char,string>mp){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        char num=digits[index];
        string value=mp[num];
        for(int i=0;i<value.size();i++){
            output.push_back(value[i]);
            solve(index+1,digits,output,ans,mp);
            output.pop_back();    
        }
        
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        if(digits.size()==1){
            string temp=mp[digits[0]];
            for(auto i:temp){
                string s(1, i);
                ans.push_back(s);
            }
            return ans;
        }
        string output="";
        solve(0,digits,output,ans,mp);
        return ans;
        
    }