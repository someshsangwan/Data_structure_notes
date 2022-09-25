#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//problem - we have given an array with N row each row (ith) have i+1 element ;
/*
1
2 3
3 6 7
  |\   can only move like this  our position is i,j so we can move (i+1,j) && (i+1,j+1)
8 9 6 10
return the minimum path to reach from top to bottom 

*/
//here recursion we will start from 0th index because there are only one element , we will go till last row ;
int solve(int i,int j,vector<vector<int>>arr,int n){
    if(i>=n){
        return INT_MAX;
    }
    if(i==n-1){
        return arr[n-1][j];

    }
    int d=arr[i][j]+solve(i+1,j,arr,n);
    int dg=arr[i][j]+solve(i+1,j+1,arr,n);
    return min(d,dg);
}
int main(){
   vector<vector<int>>arr;
   vector<int>temp1;
   temp1.push_back(1);
   arr.push_back(temp1);
   vector<int>temp2;
   temp2.push_back(2);
   temp2.push_back(3);
   arr.push_back(temp2);
   vector<int>temp3;
   temp3.push_back(3);
   temp3.push_back(6);
   temp3.push_back(7);
   arr.push_back(temp3);
   vector<int>temp4;
   temp4.push_back(8);
   temp4.push_back(9);
   temp4.push_back(6);
   temp4.push_back(10);
   arr.push_back(temp4);
   cout<<solve(0,0,arr,4)<<endl;


}