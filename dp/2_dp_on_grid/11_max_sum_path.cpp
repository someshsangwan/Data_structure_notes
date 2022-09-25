#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//ye to same hi hoga bs max path pucha h
int solve(int i,int j,vector<vector<int>>arr){
    if(i==0 && j==0){
        return arr[0][0];
    }
    if(i<0 || j<0){
        return INT_MIN;
    }
    int up=arr[i][j]+solve(i-1,j,arr);
    int left=arr[i][j]+solve(i,j-1,arr);
    return max(up,left);
}
int main(){
    vector<vector<int>>arr;
    vector<int>temp1;
    vector<int>temp2;
    temp1.push_back(1);            // 1 2
    temp1.push_back(2);            // 6 7  output will be 1+6+7=14 yes correct;
    arr.push_back(temp1);
    temp2.push_back(6);
    temp2.push_back(7);
    arr.push_back(temp2);
    cout<<solve(1,1,arr)<<endl;

}