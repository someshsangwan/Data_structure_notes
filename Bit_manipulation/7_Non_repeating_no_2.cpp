//problem - given an array every integers appears twice , 2 integers appears only once , find that 2 integers that appears once ;
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
// brute force - two nested loop   o(n^2);
// brute force 2- map - count -----o(nlogn) space also o(n);
//optimised solution bit manipulation
//lets see
int main(){
    int arr[]={2,1,2,5,1,4,4,7,3,3};
    int n=10;
    int x=0;
    //want to bit where 7 and 5 are  differ
    //  we have to find the index of rightmost set bit in xor of array;
    for(int i=0;i<n;i++){
        x=x^arr[i];
    }
    int ct=0;
    while(x){
        if(x&1==1){
            break;
        }
        ct++;
        x=x>>1;
       
    }
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n;i++){
        if(arr[i] & (1<<ct)){
            xor1=xor1^arr[i];
        }
        else{
            xor2=xor2^arr[i];
        }
    }
    cout<<xor1<<" "<<xor2<<endl;
}
