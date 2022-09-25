#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//problem - given an array , and an inteeger K fidd the max sum of subarray of size K;
// int arr[]={2,5,1,8,2,9,1}; k=3;
// 2+5+1=8,5+1+8=14,1+8+2=11,8+2+9=19,2+9+1=12  output will be =19;
// int arr[]=[ , ,i, , ,j , ] window size will be j-i+1;

    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i=0;
        int j=0;
        long long  sum=0;
        long long  res=INT_MIN;
        while(j<N){
            sum=sum+Arr[j];
            if(j-i+1<K){
                j++;
            }
            else{
                res=max(res,sum);
                sum=sum-Arr[i];
                i++;
                j++;
            }
        }
        return res;
    }
