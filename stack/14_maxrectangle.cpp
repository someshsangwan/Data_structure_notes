#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
 return the area of the largest rectangle in the histogram.
*/
    vector<int>nextsmaller(vector<int>&arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
           
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevsmaller(vector<int>&arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextsmaller(heights,n);
        vector<int>prev(n);
        prev=prevsmaller(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int height=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newarea=height*b;
            area=max(area,newarea);
        }
        return area;
    }