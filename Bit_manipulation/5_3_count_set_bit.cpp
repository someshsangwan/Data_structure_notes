#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
    int n=7;//0111  output will be 3;
    int ct=0;
    while(n!=0){
        if(n&1){
            ct++;
        }
        n=n>>1;
    }
    cout<<ct<<endl;
}