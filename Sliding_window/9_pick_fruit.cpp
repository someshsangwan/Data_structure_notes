#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* 
problem_statement

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/


//same as longest substring with k distinct element 
//yha k==2 or isse km ho skta h;
    int totalFruit(vector<int>&s) {
    int k=2;
    unordered_map<int,int>mp;
    if(s.size()==1){
        return 1;
    }
    int res=0;
    int i=0;
    int n=s.size();
    int j=0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<=k){
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