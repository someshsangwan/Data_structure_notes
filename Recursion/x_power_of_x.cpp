#include<iostream>
using namespace std;
#include<bits/stdc++.h>
 
int pitmj(int x,int n){   // iterative solution
    int  ans=1;
    int sign=n;
    if(n<0){
        n=(-1)*n;
    }
    for(int i=1;i<=n;i++){
        ans=ans*x;
    }
    if(sign>0){
    return ans;
    }
    else{
        return 1/ans;
    }
}
int recursion(int x,int n){
    if(n==0){
        return 1;
    }
    return x*recursion(x,n-1);
}
int myPow(int x, int n) {  //if  negative n is given 
    if (n==0) return 1;
    if (n==1) return x;
    if (n==-1) return 1/x;
    return myPow(x*x,n/2)*(n%2==0?1:n>0?x:1/x);
}
int main(){
    int x,n;
    cout<<"enter the valur of x and n"<<endl;
    cin>>x>>n;
    int ans=recursion(x,n);
    cout<<"ans is "<<ans<<endl;
}