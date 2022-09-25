#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
    int a=2;
    int b=3;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b<<endl;
}