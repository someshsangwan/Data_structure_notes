#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// given an array return majority element 
//majority element who occurs more than n/2 times;
//approach-1 using map;
//approach 2 moores algo
int majorityElement(const vector<int> &A) {
    int n = A.size();
    int candidate = 0;
    int count = 0;

    for(int i=0;i<n;i++){
        if(count == 0)
            candidate = A[i];
        if(A[i] == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}