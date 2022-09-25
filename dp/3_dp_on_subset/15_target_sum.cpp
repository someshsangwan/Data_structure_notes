#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
you have given an array of n positive integer and a target sum k is it possible a subset that sum is equal to K ;
ydi isme pair(koi 2 element) dhundhna hota to ye map se ezz ho jata bhailogo & bhenelogo;
ab sala ye dp ka ho gya -----------lets try bois -- hr dp ke pattern ka phla question rat lo guys baki ke ho jaenge huehuehueehueheuue;
*/
// approach 1- generate all the subsequence and check is any subsequence is present whose sum is equal to K;
// approach 2- using dp - take and non take ;
bool solve(int ind,int k,int arr[],int n){
    if(k==0){
        return true;
    }
    if(ind==0){
        return arr[0]==k;

    }
    bool not_take=solve(ind-1,k,arr,n);
    bool take=false;
    if(arr[ind]<=k){
        take=solve(ind-1,k-arr[ind],arr,n);
    }
    if(not_take || take) return true;
    else return false;

}
int main(){
    int arr[]={1,2,3,4};
    int k=4;
    int n=4;
    //output will be yes there is a subset whose sum is equal to k ({1,3},{4})----
    //Aaj 7th sem ka phla class tha hs ka academic communication ka maam bahut ache the --lol  ----  
    // demon slayer s2 ka ep 14 pura krna h abhi ;
    // jldi se question khatam krta hu;
    //op----
    bool check=solve(n-1,k,arr,n);
    cout<<check<<endl;

}