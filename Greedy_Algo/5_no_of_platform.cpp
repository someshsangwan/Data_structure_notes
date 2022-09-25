#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>

/*
iven arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.




*/

    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);  //time 0(nlogn);
        sort(dep,dep+n);
         int platform =0;
         int i=0;
         int j=0;
         int res=0;
         while(i<n && j<n){
             if(arr[i]<=dep[j]){ //matlab train gyi nhi h purane wali;
                 i++;
                 platform++;
             }
             else{
                 j++;
                 platform--;
             }
             res=max(res,platform);
         }
         return res;
  
    }