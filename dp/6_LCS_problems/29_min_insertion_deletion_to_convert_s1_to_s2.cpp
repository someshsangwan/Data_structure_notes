#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//problem is very easy 
// given 2 string 
//how much insertion and deletion is required to make s1=s2;
//s1="abcd";
//s2="anc";
// deletion - 2 -> b and d;
//insertion - 1  -> n;


//deletion -  sizeof(s1)-LCS(s1,s2);
//insertion - sizeof(s2)-LCS(s1,s2);
// LCS kr lo ache se ho jaega bhai ->
