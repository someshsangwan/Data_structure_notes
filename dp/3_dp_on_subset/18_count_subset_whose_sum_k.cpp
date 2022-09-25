#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// problem is same count no.  of subset whose sum is K;
//count wale me recursion calls ko add kr lete h;

// ind=n-1;
int solve(int ind ,int k,vector<int>arr){
     if(k==0){
        return 1;
     }
     if(ind==0){
        if(arr[0]==k){
            return 1;
        }
        else{
            return 0;
        }
     }
     int not_take=solve(ind-1,k,arr);
     int take=0;
     if(arr[ind]<=k){
        take=solve(ind-1,k-arr[ind],arr);
     }
     return take+not_take;  // in question they are asking about ways ;
}

