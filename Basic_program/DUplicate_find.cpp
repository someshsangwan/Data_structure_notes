#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// one of the most important question
// allowed time complexity =  <o(n);
// allowed space complexity - O(1);
// we will use here slow and fast pointer approach ;
/*Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear
 time using less than O(n) space and traversing the stream sequentially O(1) times.*/
int repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int slow=A[0];
    int fast=A[A[0]];
    while(slow!=fast){
        slow=A[slow];
        fast=A[A[fast]];
    }
    fast=0;
    while(fast!=slow){
        slow=A[slow];
        fast=A[fast];
    }
    return slow;
}