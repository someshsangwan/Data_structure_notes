#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Given a string A which represents a time in 24 hour HH:MM format.
Find the minimum number of minutes need to pass to reach palindromic time.
Let some time be XY:ZW then it is palindromic if X == W and Y == Z.
*/
// A = "23:59"   output 1 after 1 minute it will become 00:00 its palindrome
//A = "21:00"   outout 12 after 12 minute it will become 21:12 its palindrome

int solve(string A) {
    int x1=A[0]-'0';
    int x2=A[1]-'0';
    int y1=A[3]-'0';
    int y2=A[4]-'0';
    int hr=x1*10+x2;
    int min=y1*10+y2;
    int ct=0;
    while(true){
        if(hr/10==min%10 && min/10==hr%10){
            break;
        }
        min++;
        ct++;
        if(min%60==0){
            hr++;
            min=min%60;
        }
        if(hr%24==0){
            hr=hr%24;
        }       
    }
    return ct;
}
