#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// given that you are climbing a staircase . it takes n steps to reach the top . Each time you can either climb 1 or 2 steps;count no. of steps to reach stair;
int solve(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return solve(n-1)+solve(n-2);
}