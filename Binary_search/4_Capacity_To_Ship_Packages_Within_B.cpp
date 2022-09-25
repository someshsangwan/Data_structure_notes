#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*    
problem -
A conveyor belt has packages that must be shipped from one port to another within B days.

The ith package on the conveyor belt has a weight of A[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within B days.

ye monotonic function h na isme min dhundhna h max to kitna bhi le skte ho ; 
binary search se check krenge konsa valid bag capacity hoga , hoga to min konsa hoga ;

*/
bool check(vector<int>&weights,int x, int days) {
        int cnt=0;
        int day=0;
        for(auto i: weights) {
            if(cnt+i<=x) cnt+=i; 
            else day++, cnt=i;
        }
        if(day<days) return true;
        return false;
    }
int solve(vector<int> &A, int B) {
    int l=1;
    int r=1e9;
    for(auto i: A) l=max(l,i);
    while(1){
        int mid=(l+r)/2;
        if(check(A,mid,B)){
            //true h but hme min chahuye;
            r=mid;
        }
        else{
            l=mid;
        }
        if(r-l<=1){
            break;
        }
    }
    if(check(A,l,B)) return l;
    else return r;
}
