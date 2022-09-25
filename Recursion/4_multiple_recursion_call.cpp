#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp_r[1001];
//memset(dp_r,-1,sizeof(dp_r));
int fibonachi_iterative_solution(int n){
        if(n==1 || n==0){
            return n;
        }
        int dp[n+1]; //memoization to reduce time complexity;
        dp[0]=0;  // it is array that represent ith fibanachi no. 
        dp[1]=1;  
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
}





/*here is recursive solution0 */
int fibonachi_Recursion_solution(int n){  // its time complexity is near to 2^n  we can see from recursion tree;
    if(n==0 || n==1){
        return n;
    }
    return fibonachi_Recursion_solution(n-1)+fibonachi_Recursion_solution(n-2);
}




/* here is dp solutin to reduce time complexity of solution */
int fibonachi__dp_Recursion_solution(int n){   // here time complexity is o(n) we make it o(n) from exponential 
    if(n==0 || n==1){
        return n;
    }
    if(dp_r[n]!=-1){
        return dp_r[n];
    }
    return dp_r[n]=fibonachi__dp_Recursion_solution(n-1)+fibonachi__dp_Recursion_solution(n-2);
}
int main(){
    int n;
    memset(dp_r,-1,sizeof(dp_r));
    cout<<"enter that  no. which you find fibnacchi no "<<endl;
    cin>>n;
    cout<<fibonachi_iterative_solution(n)<<endl;
    cout<<fibonachi_Recursion_solution(n)<<endl;
}