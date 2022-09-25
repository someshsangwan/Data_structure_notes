#include<iostream>
using namespace std;
#include<bits/stdc++.h>
//problem statement-

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item  *// ek value or weight ko ek bar hi use kr skte h;
// we can have is 240.00 from the given
// capacity of sack. 

//make a ratio of their value: weight ;
//sort according to this;
class Item{
    int value;
    int weight;
};
    bool static comp(pair<int,int>a,pair<int,int>b){
        double x=(double)a.first/a.second;
        double y=(double)b.first/b.second;
        return x>y;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {     
         vector<pair<int,int>>v;
         for(int i=0;i<n;i++){
            v.push_back({arr[i].value,arr[i].weight});
            sort(v.begin(),v.end(),comp);
         }
         double res=0.0;
         for(int i=0;i<n;i++){
             if(v[i].second<=W){
                 res=res+v[i].first;
                 W=W-v[i].second;
             }
             else{
                 res=res+v[i].first*(double)W/v[i].second;
                 break;
             }
             
         }
         return res;
         
    }