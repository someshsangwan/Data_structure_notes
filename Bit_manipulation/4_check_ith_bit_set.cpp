#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//problem -- given a integer check the ith bit set or not;
int main(){
    int n=7;
    int i=3;
    if(n&(1<<i-1)){ //if indexing start from 0 then we will  take only 1<<i;
        cout<<"yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}