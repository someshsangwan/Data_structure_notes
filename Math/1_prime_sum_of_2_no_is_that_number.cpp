//Goldbach's conjecture is one of the oldest and best-known unsolved problems in number theory and all
//of mathematics. It states that every even natural number greater than two is the sum of two prime numbers.


//Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
/*If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 


*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int check_prime(int x){
    if(x==2)
    return 1;

    for(int i=2;i*i<=x;i++){
        if(x%i==0)
        return 0;
    }
    return 1;
}
vector<int> solve(int A){
    vector<int>ans;
    for(int i=2;i<A;i++){
        if(check_prime(i)&&check_prime(A-i))
       {
           ans.push_back(i);
           ans.push_back(A-i);
              return ans;
       } 
    }


}
int main(){
    int n;
    cin>>n;
    vector<int>ans=solve(n);
}