#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// its only useful when array , vectors are sorted ;
// sometimes these function are very helpful 
// if these not exist then we have to write binary serch code , how this help;
// they work in log n;
// syntax
// lower_bound(start,end,element);
// upper_bound(start,end,element);
//lower_bound- return the adress of first occurence od the element if found otherwise return the adress of greater element of the element
// example 
// 1 2 5 5 7
// auto it=lower_bound(arr,arr+n,5) or in vector --- >  lower_bound(arr.begin(),arr.end(),5);   return the adress of first 5;
// auto it =lower_bound(arr.begin(),arr.end(),6);    return the adress of 7;
// auto it=lower_bound(arr.begin(),arr.end(),8);     return the adress of n+1; last elemet 

// upper_bound -- it always return the address of greater of that element ;
//1 2 5 5 7
// auto it=upper_bound(arr,arr+n,5) or in vector --- >  upper_bound(arr.begin(),arr.end(),5);   return the adress of first 7;
// auto it =upper_bound(arr.begin(),arr.end(),6);    return the adress of 7;
// auto it=upper_bound(arr.begin(),arr.end(),8);     return the adress of n+1; end 
int main(){
    int arr[10]={2,2,3,4,5,5,8,10,15,23};
    int n=10;
    auto it=lower_bound(arr,arr+n,5);
    cout<<*it<<endl;
    // if we want to print index 
    auto it1=lower_bound(arr,arr+n,5)-arr;
    cout<<it1<<endl;

}
 