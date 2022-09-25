#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* problem - we have given an array of integers we have to print all possible subsets sum
 for example arr={2,3}
 output=0 2 3 5 , space -o(n) , time complexity-o(2^n);
 */
// approach is very simple , we have done a question related to this first we find all thee subset of given no. and then we will add



// ye to hmne phle kia uske base pe h hme 2 vector ki jrurat nhi h hm kr skte h sidha 
// generate all the subsequence of array and sum them - brute force 
void solve(vector<int>arr,int idx,int n,vector<int>&ans,vector<int>&temp){
    if(idx>=n){
        int sum=0;
        for(auto i:temp){
            sum=sum+i;
        }
        ans.push_back(sum);
        return ;
    }
    solve(arr,idx+1,n,ans,temp);
    temp.push_back(arr[idx]);
    solve(arr,idx+1,n,ans,temp);
    temp.pop_back();

}

void func(int ind,int sum,vector<int>&arr,int N,vector<int>&ans){
    if(ind==N){
        ans.push_back(sum);
        return;
    }
    func(ind+1,sum+arr[ind],arr,N,ans) ;//take element;
    func(ind+1,sum,arr,N,ans); //dont take  element;
    // we dont need to sustract arr[idx] ye sb apne app ho jaega // kr bhi skte ho kuch frk nhi pdega;
}


vector<int>subsetsum(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    vector<int>temp;
    solve(arr,0,n,ans,temp);
    return ans;
}
int main(){
    vector<int>x;
    x.push_back(2);
    x.push_back(3);
    vector<int>ans=subsetsum(x);
    for(auto i:ans){
        cout<<i<<" ";
    }
}
