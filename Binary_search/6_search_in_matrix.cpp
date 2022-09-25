#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//given sorted matrix;
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
bool searchMatrix(vector<vector<int>>& m, int target) {
         int j=m[0].size()-1 ;
        int i=0 ;
        
      while(j>=0  && i<m.size())
      {
           
            if(m[i][j]==target)
            {
                return true ;
            }
            else if(m[i][j]>target)
            {
               j-- ;
            }
           else{
               i++ ;
           }
           
        }
        return false ;
        
    }