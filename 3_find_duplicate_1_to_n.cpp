#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// question is very simple given array of size n is filled with number 1 to n every element appear exactly ones except 1 find that element in o(1) space and o(n) time 
//approach 1 use map  o(n) space and o(n) time complexity;
// optimised approach -o(1) space , o(n) time ;
// ex-  2,5,9,6,9,3,8,9,7,1;
//output -9;
//approach 1_ solw fast pointer;
// approach 2 is very ezz;
int main(){
    int arr[]={2,5,9,6,9,3,8,9,7,1};
    int n=10;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0)
        {
            cout<<abs(arr[i])<<endl;
            break;
        }
        else{
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
    }
    
}