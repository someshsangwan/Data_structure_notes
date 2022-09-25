#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void sumof(int i,int n,int &ans){
    if(i>n){
        return;
    }
    ans+=i; 
    sumof(i+1,n,ans);
    // ans+=i;  yes you can write here ----- this is backtracking bro we have seen it in lecture no. 1 ; 
     

}
// we have seen parameter recursive call 
// now we  will see functionally recursion in which we direct return value of sum;
int solve(int n){
    if(n==1){
        return 1;
    }
    return n+solve(n-1);  // for example n=3 it will run like that   3+solve(2)
                                                                  // 3+2+solve(1)
                                                                //   3+2+1 and return its value we will find ans;
}
int main(){
    int n;
    cin>>n;
    int res=0;
    sumof(0,n,res);
    cout<<res<<endl;
    cout<<solve(n)<<endl;
}


//now function to find a factorial

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

 
 