#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* probelm given a integer set 1 at given position
// for example --   110010 and i=2 then it will be  110110 --its 0th indexing ;
*/
int main(){
    int n;
    int i;
    cin>>n>>i;
    int mask=1<<i;
    n=n|mask;
    cout<<n;

}

//problem -- clear ith set bit if its zero then remains same;
int update(int n,int i){
    int mask=~(1<<i);
    return n&mask;
}

//probelm -- remove last set it;
// given 1101101 output --  1101100; last 1 is removed;
// ezzz return n&(n-1);
