#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//find the freq of occurence of given no. in o(logn) time complexity in a sorted array;
// o(n) to map se ya sidha linear traversal se kr skte h;
int main(){
    vector<int>v={5,7,7,8,8,10};
    int n=6;
    int target=8;
    //expected output =9;
    auto it1=lower_bound(v.begin(),v.end(),8)-v.begin(); // isse index pta chl jaeha ;
    auto it2=upper_bound(v.begin(),v.end(),8)-v.begin();
    cout<<it2-it1<<endl;

}