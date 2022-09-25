/*
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4

 Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int,vector<int>,greater<int>>q;
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    int j=0;
    int n=A.size();
    for(int i=0;i<C;i++){
        q.push(A[i]+B[i]);
        j++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(A[i]+A[j]>q.top()){
                    q.pop();
                    q.push(A[i]+A[j]);
                    
                }
                else{
                    break;
                }
            }
        }
    }
    vector<int>ans;
    while(!q.empty()){
        ans.push_back(q.top());
        q.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}