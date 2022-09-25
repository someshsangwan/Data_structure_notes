#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
    int n=8;
    if(n&n-1==0){//bcz n-1 wala n se chote me tutega na jaise 8 - 1000 , 7(1+2+4)-0111 and of this become 0;
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}