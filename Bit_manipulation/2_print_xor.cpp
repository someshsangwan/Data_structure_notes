#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// given interger N print xor of all from 1 to N in o(1) time complexity;
/*
N=8;
N=1  ---  1
N=2  ---  3(1^2)
N=3  ---  0(3^3)
N=4  ---  4(0^4)
N=5  ---  1(4^5)
N=6  ---  7(1^6)
N=7  ---  0(7^0)s
N=8  ---  8(0^8)
 here we can notice something 
*/
int main(){
    int n=6;
    if(n%4==1){
        cout<<1<<endl;
    }
    if(n%4==0){
        cout<<n<<endl;
    }
    if(n%4==3){
        cout<<3<<endl;
    }
    if(n%4==2){
        cout<<n+1<<endl;
    }
}