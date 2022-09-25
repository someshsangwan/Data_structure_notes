#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
problem statement-
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 
for n=3 we will get fact(3) total permutation;
so here totatl 3*2 permutation -

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
if n=3 && k=3
output will be-"213";

*/

// brute force approach - generate all permutation of given no. and  soth them and print kth permutation;
// time o(fact(n)*n) 

//Approach-2 - see the png file in this recursion folder 

// hello kids this is not a recursion problem in our 2nd approach 
    string getPermutation(int n, int k) {
        string ans="";
        vector<int>numbers;
        int fact=1;
        k=k-1;
        for(int i=1;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }    
        numbers.push_back(n);
        while(true){
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+(k/fact));
            if(numbers.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
}

