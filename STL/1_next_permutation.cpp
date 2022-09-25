#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
    string s="abcd";
    //we want to find all permutation of s;
    vector<string>temp;
    do{
        temp.push_back(s);
    }while(next_permutation(s.begin(),s.end()));

    for(auto it:temp){
        cout<<it<<" ";
    }
}