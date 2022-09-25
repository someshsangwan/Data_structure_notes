#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//problem is very simple  given a sorted matrix row-wise and col-wise find the kth smallest element in matrix;
// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

//brute force store all the value in a vector then sort it and find ans[k-1];  //n*nlong(n*n);
// priority queue --- n*nlog(k);
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{
                if(pq.top()>matrix[i][j]){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
                }
            }
        }
        return pq.top();
       
    }
//Binary search :-  n*log(n);
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
		int mid = 0;
        if(k<2) return matrix[0][0];
		while (left < right)
		{
			mid = left + (right-left)/2;
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return left;
       
    }