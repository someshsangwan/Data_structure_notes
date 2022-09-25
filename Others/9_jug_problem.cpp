#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount 
of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one 
or both buckets by the end.
*/ 

// math se ho jata 1 line me but ratne wala solution h wo
// if(target%(__gcd(cap1,cap2))==0) return true;
// else false;


//logical by BFS solution ;
bool canMeasureWater(int j , int k, int t) {
        // if(targetCapacity==jug1Capacity || targetCapacity==jug2Capacity || targetCapacity==jug1Capacity+jug2Capacity){
        //     return true;
        // }
        // if(targetCapacity>jug1Capacity+jug2Capacity){
        //     return false;
        // }
        // if(targetCapacity%(__gcd(jug1Capacity,jug2Capacity))==0){
        //     return true;
        // }
        // return false;
        int possible[]={-j,+j,-k,+k};
        int maxi=j+k;
        vector<int>vis(maxi+1,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==t){
                return true;
            }
            for(int i=0;i<4;i++){
                int c=node+possible[i];
                if(c<=maxi && c>=0 && vis[c]==0){
                    vis[c]=1;
                    q.push(c);
                }
            }
        }
        return false;
        
        
    }