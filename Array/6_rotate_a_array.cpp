#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void rotateArr(int arr[], int k, int n){
        k=k%n;
        vector<int>v;
        for(int k=0;k<k;k++){
            v.push_back(arr[k]);
        }
        int i;
        for(i=0;i<n-k;i++){
            arr[i]=arr[i+k];
        }
        int j=0;
        while(i<n){
            arr[i]=v[j];
            j++;
            i++;
        }
}