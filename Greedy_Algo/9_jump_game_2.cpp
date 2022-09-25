#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*

problem is same as jump_game_1 just print mini jump to reach last index;

*/
 
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int current=0;
        int fartest=0;
        for(int i=0;i<n-1;i++){
            fartest=max(fartest,i+nums[i]);
            if(i==current){
                current=fartest;
                jump++;
            }
        }
        return jump;
        
    }