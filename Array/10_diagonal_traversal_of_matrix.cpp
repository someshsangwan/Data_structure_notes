#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//given a matrix print diagonal traversal 
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
 vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int m=mat.size();
        int n=mat[0].size();
        int element=m*n;
        int i=0;
        int j=0;
        bool direction=true;
        while(ans.size()!=element){
            ans.push_back(mat[i][j]);
            if(direction){
                if(i==0 && j!=n-1){
                    j++;
                    direction=0;
                }
                else if(j==n-1){
                    i++;
                    direction=0;
                    
                }
                else{
                    i--;
                    j++;
                }
                
            }
            else{
                if(j==0 && i!=m-1){
                    i++;
                    direction=1;
                }
                else if(i==m-1){
                    j++;
                    direction=1;
                }
                else{
                    i++;
                    j--;
                }
                
            }
            
        }
        return ans;
    }