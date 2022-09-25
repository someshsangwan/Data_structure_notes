#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// given an array of coins u can use multiple times a coin , minimum no. of coins required to get amount;
//  [5,10,2,1] amount =57;
//  output=5+1+1=7   5 coins of 10 , 1 coin of 5 and 1 coin of 2;

int main(){
    int amount=57;
    vector<int>v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(2);
    v.push_back(1);
    //sort the  vector;
    sort(v.begin(),v.end());
    //highest amount of coin will be in the last;
    int n=v.size();
    int res=0;
    for(int i=n-1;i>=0;i--){
        int coin=amount/v[i];
        res=res+coin;
        amount=amount-v[i]*coin;
        if(amount==0){
            break;
        }
    }
    cout<<res<<endl;
}


// greedy bhi fail ho jati h kahi bhi tabhi hm dp padhte h bhai sahab;
// for example [18,1,10]  according greedy -- 18+1+1 , 3 coins but in real 10+10 2 coin is required hehehe here comes dp;