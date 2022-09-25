#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its
 next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around 
the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, 
it is guaranteed to be unique.
*/
//brute force o(n^2);
//check for every index;
//optimised solution o(n)  --->  greedy algo;
  
// very very very very Imp question for faang   
int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int sum1=0;
    int sum2=0;
    for(int i=0;i<A.size();i++){
        sum1+=A[i];
        sum2+=B[i];
    }
    if(sum1<sum2){
        return -1;
    }
    int res=0;
    int gas=0;
    for(int i=0;i<A.size();i++){
        gas+=A[i]-B[i];
        if(gas<0){
            gas=0;
            res=i+1;
        }
    }
    return res;
}