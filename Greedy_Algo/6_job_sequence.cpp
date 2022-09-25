#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* problem statement
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job
*/

// deadline ka matlab  for example deadline 3 h to hme ise 1 ya 2 ya 3 me kr sjte h 3rd se jyada me nhi;
#include<bits/stdc++.h>
bool comp(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{   int n=jobs.size();
    sort(jobs.begin(),jobs.end(),comp);
    int res=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,jobs[i][0]);
    }
    vector<int>vis(maxi+1,-1);
    
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(vis[j]==-1){
                res+=jobs[i][1];
                vis[j]=i;
                break;
            }
        }
       
    }
    return res;
    
}
